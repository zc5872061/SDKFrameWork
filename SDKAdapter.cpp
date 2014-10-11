//
//  SDKAdapter.cpp
//  HelloCpp
//
//  Created by Chukie on 14-10-11.
//
//

#include "SDKAdapter.h"


SDKAdapter* SDKAdapter::m_instance = NULL;

SDKAdapter::SDKAdapter()
{
    m_delegate = NULL;
}

SDKAdapter::~SDKAdapter()
{
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this, NOTIFICATION_LOGIN_OK);
}

SDKAdapter* SDKAdapter::getInstance()
{
    if(m_instance == NULL)
    {
        m_instance = new SDKAdapter;
        CCNotificationCenter::sharedNotificationCenter()->addObserver(m_instance, callfuncO_selector(SDKAdapter::onLogin), NOTIFICATION_LOGIN_OK, NULL);
        
    }
    return m_instance;
}

void SDKAdapter::setDelegate(SDKDelegate* del)
{
    m_delegate = del;
}

void SDKAdapter::onLogin()
{
    CCLOG("login");
    m_delegate->onLoginGameSuccess();
}