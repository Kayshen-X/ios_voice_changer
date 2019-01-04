//
//  fmod_player_effect.cpp
//  Pods-VoiceDemo
//
//  Created by kayshen on 2019/1/4.
//

#include "fmod_player_effect.hpp"


void fmod_set_audio_effect(int flag, FMOD_SYSTEM *fmod_system, FMOD_CHANNEL *fmod_channel, FMOD_DSP *fmod_dsp)
{
    switch (flag){
            case 0:
            //原生
            break;
            case 1:
            //萝莉
            //创建音频处理DSP 类型 为音频提高
            FMOD_System_CreateDSPByType(fmod_system, FMOD_DSP_TYPE_PITCHSHIFT, &fmod_dsp);
            
            //设置dsp大小
            FMOD_DSP_SetParameterFloat(fmod_dsp, FMOD_DSP_PITCHSHIFT_PITCH, 2.0);
            
            //添加一个处理单元到通道
            FMOD_Channel_AddDSP(fmod_channel, 0, fmod_dsp);
            break;
            
            case 2:
            //惊悚
            //创建音频处理DSP 类型 为颤抖
            FMOD_System_CreateDSPByType(fmod_system, FMOD_DSP_TYPE_TREMOLO, &fmod_dsp);
            //设置低频频率
            FMOD_DSP_SetParameterFloat(fmod_dsp, FMOD_DSP_TREMOLO_FREQUENCY, 20);
            //设置声音歪斜
            FMOD_DSP_SetParameterFloat(fmod_dsp, FMOD_DSP_TREMOLO_SKEW, 0.5);
            
            //添加一个处理单元到通道
            FMOD_Channel_AddDSP(fmod_channel, 0, fmod_dsp);
            break;
            
            case 3:
            //大叔
            //创建音频处理DSP 类型 为音频提高
            FMOD_System_CreateDSPByType(fmod_system, FMOD_DSP_TYPE_PITCHSHIFT, &fmod_dsp);
            //设置dsp大小
            FMOD_DSP_SetParameterFloat(fmod_dsp, FMOD_DSP_PITCHSHIFT_PITCH, 0.5);
            
            //添加一个处理单元到通道
            FMOD_Channel_AddDSP(fmod_channel, 0, fmod_dsp);
            break;
            case 4:
        {
            //搞怪
            float mfrequency = 0;
            //得到频率
            FMOD_Channel_GetFrequency(fmod_channel, &mfrequency);
            FMOD_Channel_SetFrequency(fmod_channel, mfrequency * 2);
            break;
        }
            
            case 5 :
        {
            //空灵
            //创建音频处理DSP 类型 为音频提高
            FMOD_System_CreateDSPByType(fmod_system, FMOD_DSP_TYPE_ECHO, &fmod_dsp);
            //设置dsp大小  延迟声
            FMOD_DSP_SetParameterFloat(fmod_dsp, FMOD_DSP_ECHO_DELAY, 300);
            //回音音量
            FMOD_DSP_SetParameterFloat(fmod_dsp, FMOD_DSP_ECHO_FEEDBACK, 20);
            
            //添加一个处理单元到通道
            FMOD_Channel_AddDSP(fmod_channel, 0, fmod_dsp);
            break;
        }
            
    }
}
