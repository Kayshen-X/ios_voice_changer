//
//  FMPlayer.h
//  VoiceDemo
//
//  Created by kayshen on 2019/1/4.
//  Copyright © 2019 kayshen. All rights reserved.
//

#ifndef FMPlayer_h
#define FMPlayer_h

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, FMPlayerOptionFlag) {
    FMPlayerOptionFlagOriginal,//原声
    FMPlayerOptionFlagLolita,  //萝莉
    FMPlayerOptionFlagThriller,//惊悚
    FMPlayerOptionFlagUncle,   //大叔
    FMPlayerOptionFlagFunny,   //搞怪
    FMPlayerOptionFlagVacant,  //空灵
};

@interface FMPlayerOption : NSObject

@property (nonatomic, strong) NSString *name;
@property (nonatomic, assign) FMPlayerOptionFlag flag;

+ (NSArray<FMPlayerOption *> *)defaultOptions;

@end


@interface FMPlayer : NSObject

- (instancetype)initWithPath:(NSString *)path option:(FMPlayerOption *)option;

- (void)play;
- (void)pause;
- (void)stop;

@end

#endif /* FMPlayer_h */
