struct task{
    long state;
    long number;
    long signal;
    long priority;
    int exit_code; /*return 1; - exit_code = 1, return 0; - exit_code = 0 0 exit successfully 1 error or another code*/
    struct m_inode * root;   
};

struct m_inode{
    unsigned short mode;
    unsigned short uid;
    unsigned short size;
};