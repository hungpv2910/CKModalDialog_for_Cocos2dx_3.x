CKModalDialog_for_Cocos2dx_3.x
==============================

This is a ModalDialog for Cocos2dx 3.x,it can show any view inherit from Node.

###USAGE：
show:
```
CKModalDialog::getInstance()->pushContentView(Sprite::createWithSpriteFrameName("523.png"));
```
hide:
```
CKModalDialog::getInstance()->popContentView();
```
You could push as many views as you want,and ModalDialog will manage them for you
