/*  strings.c
*
*
*
*/

#include "tao.h"



const char distao[] =
	"\tTao's Editor\n"
	"\t一个简单的文本编辑器\n"
	"\t赞助\t联系作者\n"
	"\n请使用 tao --help 或 tao -h 查看帮助信息！\n"
	;

const char error[] =
	"\n参数错误！\n"
	"\n请使用："
	"tao -h 或者 tao --help 来查看帮助\n"
	;

const char help[] =
	"tao [-x] [File Name]\n"
	"tao [File Name]\t直接打开或创建文件\n"
	"-h\t--help  查看帮助信息\n"
	"-t\t--than  对比两个文件\n"
	"-d\t--display  把文件内容展示到终端\n"
	"-g\t--gnome  图形化打开文件\n"
	"\n详细使用方法\n"
	"tao -t file1.txt file2.txt\n"
	"tao -d file.txt\n"
	"tao -g file.txt\n"
	;