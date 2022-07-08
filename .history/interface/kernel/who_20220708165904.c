/**
 * @file who.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-08
 *
 * @copyright Copyright (c) 2022
 * 实现系统调用sys_iam和sys_whoami两个系统调用函数,主要功能为:
 * 第一个iam函数完成的功能是将字符串参数 name 的内容拷贝到内核中保存下来。
 要求 name 的长度不能超过 23 个字符。
 返回值是拷贝的字符数。如果 name 的字符个数超过了 23，
 则返回 “-1”，并置 errno 为 EINVAL
 * 第二个whoami函数完成的功能为它将内核中由 iam() 
 保存的名字拷贝到 name 指向的用户地址空间中，
 同时确保不会对 name 越界访存（name 的大小由 size 说明）。
 返回值是拷贝的字符数。如果 size 小于需要的空间，
 则返回“-1”，并置 errno 为 EINVAL
 */
#include <asm/segment.h>
#include <errno.h>

#include <linux/kernel.h>

#define NAMELEN 23

int sys_iam(const char *name) {

    //将数据拷贝到内核态
    //统计输入name字符串的长度
    unsigned int namelen = 0;
    int ret = -1;
    while(get_fs_byte(name) != "\0") {
        namelen++;
    }

    if(namelen > NAMELEN) {
    printK();    
    return -(EINVAL)
    }else {

    }

    return ret;
}