#ifndef VIDEO_READER_HPP
#define VIDEO_READER_HPP
extern "C" {
    #include <libavformat/avformat.h>
    #include <libavcodec/avcodec.h>
}
class VideoReader{
public: 
    VideoReader(const char* filename);
private: 
    AVFormatContext* format_ctx; 
    
};

#endif