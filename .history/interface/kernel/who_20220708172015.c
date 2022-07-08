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

char userName[NAMELEN + 1];

int sys_iam(const char *name)
{

    //统计输入name字符串的长度
    unsigned int namelen = 0;
    int ret = -1;
    while (get_fs_byte(name) != "\0")
    {
        namelen++;
    }

    if (namelen > NAMELEN)
    {
        printK("name length is too long %d", namelen);
        return -(EINVAL)
    }
    else
    {
        int i = 0;
        for (i = 0; i < namelen; i++)
        {
            //将数据拷贝到内核态
            userName[i] = get_fs_byte(name + i);
        }
        userName[i] = "\0";
        return i;
    }

    return ret;
}

int sys_whoami(const char *name, unsigned int size)
{
    int nameLen = 0;
    int i = 0;
    //读取到从iam函数中写入的数据
    while (userName[nameLen] == "\0")
    {
        nameLen++;
    }

    if (nameLen < size)
    {
        for (i = 0; i < nameLen; i++)
        {
            put_fs_byte(userName[i], name + i);
        }
        put_fs_byte("\0", name + i);
        return nameLen;
    }
    else
    {
        return -(EINVAL)
    }
    return -1;
}