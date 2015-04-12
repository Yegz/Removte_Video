#ifndef CAMERA__
#define CAMERA__


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/videodev2.h>


#define COUNT_CIF		352 * 288 * 4

typedef struct
{
    void   *start;
    size_t  length;

} VIDEO_BUF;

typedef struct
{
    int fd;										// camara file descriptor
    VIDEO_BUF *video_buf;						// video buffer
    int buf_num;								// number of video buffer
    int index;									// index of buffer in reading

} CAM_V4L;

// error code
enum
{
    ERR_CAM_OPEN,								// open camara unsuccessfully
    ERR_CAM_NOT_OPEN,							// camera is not opened
    ERR_CAM_VIDIOC_QUERYCAP = -2000,			// get camara capbilityc error
    ERR_CAM_VIDEO_CAPTURE,						// camara is not support video capture
    ERR_CAM_STREAMING,							// camara is not support streaming
    ERR_CAM_VIDIOC_S_FMT,						// set video format unsuccessfully
    ERR_CAM_VIDIOC_REQBUFS,						// request buffers unsuccessfully
    ERR_CAM_VIDIOC_QUERYBUF,					// query buffer to map
    ERR_CAM_MAP,								// camara map failed
    ERR_CAM_VIDIOC_QBUF,						// set camara buffer
    ERR_CAM_VIDIOC_STREAMON,					// streaming on failed
    ERR_CAM_VIDIOC_DQBUF,						// get data buffer failed
};
int v4l2_get_capability(CAM_V4L *cam_v4l);
int v4l2_set_fmt(CAM_V4L *cam_v4l);

int v4l2_set_memory(CAM_V4L *cam_v4l);
int v4l2_read(CAM_V4L *cam_v4l);
int v4l2_init(CAM_V4L *cam_v4l, const char *dev_name);
void v4l2_close(CAM_V4L *cam_v4l);

#endif
