//
//  CKModalDialog.h
//
//  Created by CK on 14-8-14.
//
//

#ifndef __GameClientPlatform__CKModalDialog__
#define __GameClientPlatform__CKModalDialog__

#include <iostream>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class CKModalDialog :public Node{
public:
    virtual bool init();
    static CKModalDialog* getInstance();
    void pushContentView(cocos2d::Node *pNode);
    void pushContentView(cocos2d::Node *pNode,Point position);
    void pushContentView(cocos2d::Node *pNode,bool animation);
    void pushContentView(cocos2d::Node *pNode,Point position,bool animation);
    void popContentView();
private:
    static CKModalDialog* _instance;
    Vector<LayerColor*> _contentViewVector;
};

#endif /* defined(__GameClientPlatform__ModalDialog__) */
