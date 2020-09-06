//
// Created by expoli on 2020/9/6.
//

#ifndef TEST_DLINKLIST_H
#define TEST_DLINKLIST_H

namespace dlinklist {
#define ElemType int
    typedef struct Dnode {
        ElemType data;
        struct Dnode *prior;
        struct Dnode *next;
    } DLinkList;


}

#endif //TEST_DLINKLIST_H
