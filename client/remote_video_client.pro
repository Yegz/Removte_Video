TEMPLATE = app

LIBS += -lpthread -ljpeg
DEPENDPATH += . decoder encoder
INCLUDEPATH += . encoder decoder

SOURCES =   main.cpp              \
            camera.cpp            \
            yuyv_to_rgb24.cpp     \
            local_time.cpp        \
            sys_debug.cpp         \
            c_socket.cpp          \
            client_login.cpp      \
            decoder/convert.cpp   \
            decoder/DGlobal.cpp   \
            decoder/GetBits.cpp   \
            decoder/GetBlk.cpp    \
            decoder/GetHdr.cpp    \
            decoder/GetPic.cpp    \
            decoder/GetVlc.cpp    \
            decoder/Idct.cpp      \
            decoder/Idctref.cpp   \
            decoder/Indices.cpp   \
            decoder/Recon.cpp     \
            decoder/Sac.cpp       \
            decoder/Sactbls.cpp   \
            decoder/Tmndec.cpp    \
            decoder/YuvToRgb.cpp  \
            encoder/coder.cpp     \
            encoder/countbit.cpp  \
            encoder/dct.cpp       \
            encoder/Global.cpp    \
            encoder/huffman.cpp   \
            encoder/libr263.cpp   \
            encoder/mot_est.cpp   \
            encoder/pred.cpp      \
            encoder/quant.cpp     \
            encoder/rlib.cpp      \
            encoder/stream.cpp    \

HEADERS =   camera.h              \
            yuyv_to_rgb24.h       \
            local_time.h          \
            sys_debug.h           \
            c_socket.h            \
            client_login.h        \
            decoder/convert.h     \
            decoder/decdef.h      \
            decoder/decstruct.h   \
            decoder/DGlobal.h     \
            decoder/GetBits.h     \
            decoder/GetBlk.h      \
            decoder/GetHdr.h      \
            decoder/GetPic.h      \
            decoder/GetVlc.h      \
            decoder/Idct.h        \
            decoder/Idctref.h     \
            decoder/Indices.h     \
            decoder/Recon.h       \
            decoder/Sac.h         \
            decoder/Sactbls.h     \
            decoder/Tmndec.h      \
            encoder/coder.h       \
            encoder/config.h      \
            encoder/countbit.h    \
            encoder/ctables.h     \
            encoder/dct.h         \
            encoder/def.h         \
            encoder/Global.h      \
            encoder/huffman.h     \
            encoder/libr263.h     \
            encoder/mot_est.h     \
            encoder/owntypes.h    \
            encoder/pred.h        \
            encoder/quant.h       \
            encoder/rlib.h        \
            encoder/stream.h      \
            encoder/struct.h      \

FORMS = login.ui                \
