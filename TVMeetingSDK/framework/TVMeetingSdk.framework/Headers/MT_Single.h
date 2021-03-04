//
//  MT_Single.h
//  jsh-app-meeting-ios
//
//  Created by 巨商汇 on 2020/4/2.
//  Copyright © 2020 巨商汇. All rights reserved.
//

//拼接方法名
/** 创建单例的方法 */
#define MT_InterfaceSingle(name) +(instancetype)share##name;

/** 销毁单例的方法 */
#define MT_InterfaceDestroySingle(name) +(void)destory##name;

#if __has_feature(objc_arc)
// 如果是ARC

#define MT_ImplementationSingle(name) +(instancetype)share##name\
\
{\
return [[self alloc]init];\
}\
static id _instance;\
static dispatch_once_t onceToken;\
+(instancetype)allocWithZone:(struct _NSZone *)zone\
{\
dispatch_once(&onceToken, ^{\
_instance = [super allocWithZone:zone];\
});\
return _instance;\
}\
-(id)copyWithZone:(NSZone *)zone\
{\
return _instance;\
}\
-(id)mutableCopyWithZone:(NSZone *)zone\
{\
return _instance;\
}
#define MT_ImplementationDestroySingle(name) +(void)destory##name\
\
{\
_instance = nil;\
onceToken = 0l;\
}

#else
//如果是MRC
#define MT_ImplementationSingle(name) +(instancetype)share##name\
\
{\
return [[self alloc]init];\
}\
static id _instance;\
static dispatch_once_t onceToken;\
+(instancetype)allocWithZone:(struct _NSZone *)zone\
{\
dispatch_once(&onceToken, ^{\
_instance = [super allocWithZone:zone];\
});\
return _instance;\
}\
-(id)copyWithZone:(NSZone *)zone\
{\
return _instance;\
}\
-(id)mutableCopyWithZone:(NSZone *)zone\
{\
return _instance;\
}\
-(oneway void)release\
{}\
-(instancetype)retain\
{\
return _instance;\
}\
-(NSUInteger)retainCount\
{\
return MAXFLOAT;\
}
#define MT_ImplementationDestroySingle(name) +(void)destory##name\
\
{\
_instance = nil;\
onceToken = 0l;\
}
#endif
