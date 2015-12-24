/****************************************************************************
 Copyright (c) 2014 cocos2d-x.org
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __cocos2d_libs__WidgetCallBackHandlerProtocol__
#define __cocos2d_libs__WidgetCallBackHandlerProtocol__

#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "ui/UIWidget.h"

#define CS_MEMBERVARIABLEASSIGNER_GLUE(TARGET, MEMBERVARIABLENAME, MEMBERVARIABLETYPE, MEMBERVARIABLE) \
    if (target == TARGET && 0 == strcmp(memberVariableName, (MEMBERVARIABLENAME))) { \
        MEMBERVARIABLETYPE pOldVar = MEMBERVARIABLE; \
        MEMBERVARIABLE = dynamic_cast<MEMBERVARIABLETYPE>(node); \
        CC_ASSERT(MEMBERVARIABLE); \
        if (pOldVar != MEMBERVARIABLE) { \
            CC_SAFE_RELEASE(pOldVar); \
		} \
        return true; \
	}

#define CS_SELECTORRESOLVER_TOUCH_GLUE(TARGET, SELECTORNAME, METHOD) if(TARGET && strcmp(callBackName.c_str(), SELECTORNAME) == 0) { \
	return CC_CALLBACK_2(METHOD, TARGET); \
}

#define CS_SELECTORRESOLVER_CLICK_GLUE(TARGET, SELECTORNAME, METHOD) if(TARGET && strcmp(callBackName.c_str(), SELECTORNAME) == 0) { \
	return CC_CALLBACK_1(METHOD, TARGET); \
}

namespace cocostudio {
    
    class CC_STUDIO_DLL WidgetCallBackHandlerProtocol
    {
    public:
        WidgetCallBackHandlerProtocol() {};
        virtual ~WidgetCallBackHandlerProtocol() {};
        
		virtual cocos2d::ui::Widget::ccWidgetTouchCallback onLocateTouchCallback(const std::string &callBackName){ return nullptr; };
        virtual cocos2d::ui::Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName){ return nullptr; };
        virtual cocos2d::ui::Widget::ccWidgetEventCallback onLocateEventCallback(const std::string &callBackName){ return nullptr; };
		virtual bool onAssignCSMemberVariable(cocos2d::Ref* target, const char* memberVariableName, cocos2d::Node* node){ return false; };
		virtual void onNodeLoaded(){ };

    };
}

#endif /* defined(__cocos2d_libs__WidgetCallBackHandlerProtocol__) */
