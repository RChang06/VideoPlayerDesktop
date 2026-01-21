#include "VideoReader.hpp"
#include <iostream>
#include <string>

VideoReader::VideoReader(const char* filename){
    //Allocates and fills an AVFormatContext struct
    if (avformat_open_input(&format_ctx, filename, NULL, NULL)< 0){
        std::cerr << "Error: Could not open file "<<filename <<std::endl;
        return; 
    }

    //Scane the file for stream info
    if (avformat_find_stream_info(format_ctx, NULL)){
        std::cerr << "Error: Could not find stream information" << std::endl;
        return;    
    }
}