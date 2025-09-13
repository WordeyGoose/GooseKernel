#ifndef GOOSE_FS_H
#define GOOSE_FS_H
void fs();
void fs_init();
void buff_init();
void buff_main();
extern int exec_file();
extern int close_file();
extern int new_file();

struct buff_head{
    char * data;
    unsigned short device;
    unsigned short blocknum;
    unsigned short uptodate;
    unsigned short dirty;
    unsigned short userblock; /* this block using user*/
    unsigned short locked;
    struct task * wait;
    struct buff_head * preview;
    struct buff_head * next;
    struct buff_head * next_free;
    struct buff_head * preview_free;
};

struct file{
    unsigned short mode;
    unsigned short flags;
    unsigned short id;
    struct m_inode * f_inode;
};

void create_block(struct m_inode * inode, int block);
void free_block(int device, int block);
#endif