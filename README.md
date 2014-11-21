CKModalDialog_for_Cocos2dx_3.x
==============================

This is a ModalDialog for Cocos2dx 3.x,it can show any view inherit from Node.

###USAGE：
Drag ModalDialog.h and ModalDialog.cpp to your project
Then typing #include "ModalDialog.h" in the file you want use it

Show:
```
CKModalDialog::getInstance()->pushContentView(Sprite::createWithSpriteFrameName("523.png"));
```
Hide:
```
CKModalDialog::getInstance()->popContentView();
```
You can push as many views as you want,and ModalDialog will manage them for you

###APIS
```
void pushContentView(cocos2d::Node *pNode);
void pushContentView(cocos2d::Node *pNode,Point position);
void pushContentView(cocos2d::Node *pNode,bool animation);
void pushContentView(cocos2d::Node *pNode,Point position,bool animation);
void popContentView();
```
