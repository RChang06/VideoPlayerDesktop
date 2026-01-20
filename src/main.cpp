#include <iostream>

extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
}

int main() {
    AVFormatContext* format_ctx = avformat_alloc_context();
    
    const char* url = "C:/assets/videos/video.mp4";

    if (avformat_open_input(&format_ctx, url, NULL, NULL) != 0) {
        std::cerr << "Could not open file!" << std::endl;
        return -1;
    }

    if (avformat_find_stream_info(format_ctx, NULL) < 0) {
        std::cerr << "Could not find stream information!" << std::endl;
        return -1;
    }

    for (unsigned int i = 0; i < format_ctx->nb_streams; i++) {
        AVCodecParameters* local_codec_params = format_ctx->streams[i]->codecpar;
        
        if (local_codec_params->codec_type == AVMEDIA_TYPE_VIDEO) {
            std::cout << "Stream " << i << ": VIDEO (Res: " 
                      << local_codec_params->width << "x" 
                      << local_codec_params->height << ")" << std::endl;
        } else if (local_codec_params->codec_type == AVMEDIA_TYPE_AUDIO) {
            std::cout << "Stream " << i << ": AUDIO (" 
                      << local_codec_params->ch_layout.nb_channels << " channels)" << std::endl;
        }
    }

    avformat_close_input(&format_ctx);
    return 0;
}