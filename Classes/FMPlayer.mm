//
//  FMPlayer.m
//  Pods-VoiceDemo
//
//  Created by kayshen on 2019/1/4.
//


#import "FMPlayer.h"
#include "fmod_player.hpp"

@implementation FMPlayerOption

+ (NSArray<FMPlayerOption *> *)defaultOptions
{
    NSMutableArray *array = [NSMutableArray array];
    {
        FMPlayerOption *option = [[FMPlayerOption alloc] init];
        option.name = @"原声";
        option.flag = FMPlayerOptionFlagOriginal;
        [array addObject:option];
    }
    
    {
        FMPlayerOption *option = [[FMPlayerOption alloc] init];
        option.name = @"萝莉";
        option.flag = FMPlayerOptionFlagLolita;
        [array addObject:option];
    }
    
    {
        FMPlayerOption *option = [[FMPlayerOption alloc] init];
        option.name = @"惊悚";
        option.flag = FMPlayerOptionFlagThriller;
        [array addObject:option];
    }
    
    {
        FMPlayerOption *option = [[FMPlayerOption alloc] init];
        option.name = @"大叔";
        option.flag = FMPlayerOptionFlagUncle;
        [array addObject:option];
    }
    
    {
        FMPlayerOption *option = [[FMPlayerOption alloc] init];
        option.name = @"搞怪";
        option.flag = FMPlayerOptionFlagFunny;
        [array addObject:option];
    }
    
    {
        FMPlayerOption *option = [[FMPlayerOption alloc] init];
        option.name = @"空灵";
        option.flag = FMPlayerOptionFlagVacant;
        [array addObject:option];
    }
    return array;
}

@end

@interface FMPlayer ()

@property (nonatomic, strong) NSString *path;
@property (nonatomic, strong) FMPlayerOption *option;


@end

@implementation FMPlayer
{
    FPlayer *_player;
}


- (instancetype)initWithPath:(NSString *)path option:(FMPlayerOption *)option
{
    if (self = [super init]) {
        self.path = path;
        self.option = option;
        play_init(&_player);
    }
    return self;
}

- (void)dealloc
{
    play_close(_player);
}

- (void)play
{
    play_start(_player, [self.path UTF8String],self.option.flag);
    [NSObject cancelPreviousPerformRequestsWithTarget:self selector:@selector(checkIsPlaying) object:nil];
    [self performSelector:@selector(checkIsPlaying) withObject:nil afterDelay:0.1];
}

- (void)pause
{
    play_continue_pause(_player, 1);
    [NSObject cancelPreviousPerformRequestsWithTarget:self selector:@selector(checkIsPlaying) object:nil];
}

- (void)stop
{
    play_stop(_player);
}

- (void)checkIsPlaying
{
    if (play_is_playing(_player)) {
        NSLog(@"播放结束");
        [self stop];
    } else {
        [self performSelector:@selector(checkIsPlaying) withObject:nil afterDelay:0.1];
        NSLog(@"正在播放");
    }
}

@end
