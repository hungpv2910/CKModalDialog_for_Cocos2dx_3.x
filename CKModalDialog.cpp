//
//  CKModalDialog.cpp
//
//  Created by CK on 14-8-14.
//
//

#include "CKModalDialog.h"
#define kWINSIZE  Director::getInstance()->getWinSize()
#define kGetNodeWidth(node) node->getBoundingBox().size.width
#define kGetNodeHeight(node) node->getBoundingBox().size.height
#define kMaskAlpha 90

USING_NS_CC;
CKModalDialog* CKModalDialog::_instance = nullptr;

CKModalDialog* CKModalDialog::getInstance(){
    if(_instance == nullptr){
        _instance = new CKModalDialog();
    }
    return _instance;
}

bool CKModalDialog::init(){
    if (!Node::init()) {
        return false;
    }
    return true;
}

void CKModalDialog::pushContentView(cocos2d::Node *pNode){
    pushContentView(pNode, Point(kWINSIZE.width/2,kWINSIZE.height/2));
}

void CKModalDialog::pushContentView(cocos2d::Node *pNode,Point position){
    pushContentView(pNode, position,true);
}

void CKModalDialog::pushContentView(cocos2d::Node *pNode,bool animation){
    pushContentView(pNode, Point(kWINSIZE.width/2,kWINSIZE.height/2),animation);
}

void CKModalDialog::pushContentView(cocos2d::Node *pNode,Point position,bool animation){
    auto bgLayer = LayerColor::create(Color4B(0, 0, 0, 0), kWINSIZE.width, kWINSIZE.height);
    Director::getInstance()->getRunningScene()->addChild(bgLayer,9999);
    auto maskLayer = LayerColor::create(Color4B(0, 0, 0, 0), kWINSIZE.width, kWINSIZE.height);
    bgLayer->addChild(maskLayer,0);
    maskLayer->runAction(FadeTo::create(0.15, kMaskAlpha));
    
    auto bgItem=MenuItem::create();
    bgItem->setCallback([=](Ref* pSender){ popContentView();});
    bgItem->setContentSize(kWINSIZE);
    auto bgMenu=Menu::create(bgItem,NULL);
    bgLayer->addChild(bgMenu);
    
    auto modalItem=MenuItem::create();
    modalItem->setContentSize(pNode->getBoundingBox().size);
    auto modalBgMenu=Menu::create(modalItem,NULL);
    modalBgMenu->setPosition(position);
    bgLayer->addChild(modalBgMenu,1);
    
    pNode->setAnchorPoint(Point(0.5,0.5));
    pNode->setPosition(position);
    bgLayer->addChild(pNode,2);
    if(animation){
        pNode->setScale(.8f);
        auto scaleto1 = ScaleTo::create(0.1f, 1.1f);
        auto scaleto2 = ScaleTo::create(0.07f, .9f);
        auto scaleto3 = ScaleTo::create(0.05f, 1.0f);
        pNode->runAction(Sequence::create(scaleto1,scaleto2,scaleto3, NULL));
    }
    _contentViewVector.pushBack(bgLayer);
}

void CKModalDialog::popContentView(){
    if(_contentViewVector.size()>0){
        _contentViewVector.back()->removeFromParentAndCleanup(true);
        _contentViewVector.popBack();
    }
}

