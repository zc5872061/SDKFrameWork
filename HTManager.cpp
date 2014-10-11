//
//  HTManager.cpp
//  MyTest
//
//  Created by Chukie on 14-10-9.
//
//

#include "HTManager.h"

extern void _showLoginView();
extern void _initPlatForm();


HTManager* HTManager::m_instance = NULL;

HTManager::HTManager()
{
    
}

HTManager::~HTManager()
{
    
}

HTManager* HTManager::getHTManagerInstance()
{
    if(m_instance == NULL)
    {
        m_instance = new HTManager;
    }
    return m_instance;
    
}

bool HTManager::init()
{
    bool ret = false;
    do
    {
    }
    while (0);
    return ret;
}

void HTManager::showLoginView()
{
    _showLoginView();
}

void HTManager::initPlatForm()
{
    _initPlatForm();
}