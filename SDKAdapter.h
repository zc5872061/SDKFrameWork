//
//  SDKAdapter.h
//  HelloCpp
//
//  Created by Chukie on 14-10-11.
//
//

#ifndef __HelloCpp__SDKAdapter__
#define __HelloCpp__SDKAdapter__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

#define NOTIFICATION_LOGIN_OK "NOTIFICATION_LOGIN_OK"

class SDKDelegate
{
public:
    virtual void onLoginGameSuccess()=0;
};


class SDKAdapter:public CCObject
{
public:
    SDKAdapter();
    virtual ~SDKAdapter();
    static SDKAdapter* getInstance();
    void setDelegate(SDKDelegate* del);
    void onLogin();
protected:
    SDKDelegate* m_delegate;
    static SDKAdapter* m_instance;
};


#endif /* defined(__HelloCpp__SDKAdapter__) */
