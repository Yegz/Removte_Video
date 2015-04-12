#include "camera.h"
int v4l2_get_capability(CAM_V4L *cam_v4l)
{
    int ret = 0;
    int fd = cam_v4l->fd;
    struct v4l2_capability cap;

    if (cam_v4l->fd < 0) {
        ret = ERR_CAM_NOT_OPEN;
        goto exit;
    }

    if (::ioctl (fd, VIDIOC_QUERYCAP, &cap) == -1) {
        ret = ERR_CAM_VIDIOC_QUERYCAP;/*是否具备视频输入能力*/
        goto exit;
    }
    if (!(cap.capabilities & V4L2_CAP_VIDEO_CAPTURE)) {
        ret = ERR_CAM_VIDEO_CAPTURE;/*是否具备视频捕捉能力*/
        goto exit;
    }
    if (!(cap.capabilities & V4L2_CAP_STREAMING)) {
        ret = ERR_CAM_STREAMING;
        goto exit;
    }

exit:
    return ret;
}
int v4l2_set_fmt(CAM_V4L *cam_v4l)
{
    int ret = 0;
    int fd = cam_v4l->fd;
    struct v4l2_format fmt;

    if (cam_v4l->fd < 0) {
        ret = ERR_CAM_NOT_OPEN;
        goto exit;
    }

    memset(&fmt, 0, sizeof(fmt));
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width = 352;
    fmt.fmt.pix.height = 288;
    fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
    fmt.fmt.pix.field       = V4L2_FIELD_INTERLACED;
    if (::ioctl(fd, VIDIOC_S_FMT, &fmt) == -1){
        ret = ERR_CAM_VIDIOC_S_FMT;
        goto exit;
    }

exit:
    return ret;
}
int v4l2_set_memory(CAM_V4L *cam_v4l)
{
    int i = 0;
    int ret = 0;
    int fd = cam_v4l->fd;
    struct v4l2_requestbuffers req;
    struct v4l2_buffer buf;

    if (cam_v4l->fd < 0) {
        ret = ERR_CAM_NOT_OPEN;
        goto exit;
    }

    memset(&req, 0, sizeof (req));
    req.count = cam_v4l->buf_num;
    req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    req.memory = V4L2_MEMORY_MMAP;
    if (::ioctl(fd, VIDIOC_REQBUFS, &req) < 0) {
        ret = ERR_CAM_VIDIOC_REQBUFS;
        goto exit;
    }

    if (cam_v4l->video_buf != NULL) {
        free(cam_v4l->video_buf);
    }
    cam_v4l->video_buf = (VIDEO_BUF *)calloc(req.count, sizeof(VIDEO_BUF));
    for (i = 0; i < (int)req.count; i++) {
        memset(&buf, 0, sizeof(buf));
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        buf.index = i;
        if (::ioctl(fd, VIDIOC_QUERYBUF, &buf) == -1) {
            ret = ERR_CAM_VIDIOC_QUERYBUF;
            goto exit;
        }

        cam_v4l->video_buf[i].length = buf.length;
        cam_v4l->video_buf[i].start = mmap(NULL, buf.length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, buf.m.offset);
        if (cam_v4l->video_buf[i].start == MAP_FAILED) {
            ret = ERR_CAM_MAP;
            goto exit;
        }

        if (::ioctl(fd, VIDIOC_QBUF, &buf) == -1) {
            ret = ERR_CAM_VIDIOC_QBUF;
            goto exit;
        }
    }

exit:
    return ret;
}
int v4l2_read(CAM_V4L *cam_v4l)
{
    int ret = 0;
    int fd = cam_v4l->fd;
    struct v4l2_buffer buf;

    if (cam_v4l->fd < 0) {
        ret = ERR_CAM_NOT_OPEN;
        goto exit;
    }

    memset(&buf,0,sizeof(buf));
    buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.memory = V4L2_MEMORY_MMAP;
    if (cam_v4l->index >= 0) {
        buf.index = cam_v4l->index;
    }
    ::ioctl(fd, VIDIOC_QBUF, &buf);

    if (::ioctl(fd, VIDIOC_DQBUF, &buf) == -1) {
        ret = ERR_CAM_VIDIOC_DQBUF;
        goto exit;
    }
    cam_v4l->index = buf.index;

exit:
    return ret;
}
int v4l2_init(CAM_V4L *cam_v4l, const char *dev_name)
{
    int ret = 0;
    int fd = 0;
    enum v4l2_buf_type type;

    fd = ::open(dev_name, O_RDWR);
    if (fd == -1) {
        ret = ERR_CAM_OPEN;
        goto exit;
    }
    cam_v4l->fd = fd;
    cam_v4l->video_buf = NULL;
    cam_v4l->buf_num = 3;
    cam_v4l->index = -1;

    ret = v4l2_get_capability(cam_v4l);
    if (ret) {
        goto exit;
    }

    ret = v4l2_set_fmt(cam_v4l);
    if (ret) {
        goto exit;
    }

    ret = v4l2_set_memory(cam_v4l);
    if (ret) {
        goto exit;
    }

    type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (::ioctl (fd, VIDIOC_STREAMON, &type) < 0) {
        ret = ERR_CAM_VIDIOC_STREAMON;
        goto exit;
    }

exit:
    return ret;
}
void v4l2_close(CAM_V4L *cam_v4l)
{
    int i = 0;

    if (cam_v4l->fd < 0) {
        goto exit;
    }

    for (i = 0; i < cam_v4l->buf_num; i++) {
        munmap(cam_v4l->video_buf[i].start, cam_v4l->video_buf[i].length);
    }
    free(cam_v4l->video_buf);
    close(cam_v4l->fd);
    cam_v4l->fd = -1;

exit:
    return;
}
