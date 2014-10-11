//
//  HTManager.h
//  MyTest
//
//  Created by Chukie on 14-10-9.
//
//

#ifndef __MyTest__HTManager__
#define __MyTest__HTManager__

#include <iostream>

class HTManager
{
public:
    HTManager();
    static HTManager* getHTManagerInstance();
    ~HTManager();
    bool init();
    void showLoginView();
    void initPlatForm();
protected:
    static HTManager* m_instance;
};

#endif /* defined(__MyTest__HTManager__) */
