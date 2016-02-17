/* **************************************************************************
*
*
     __  __             _            _      _____             
    |  \/  |           | |          | |    / ____|    /\      
    | \  / |_   _  ___ | |_ ___  ___| |_  | (___     /  \     
    | |\/| | | | |/ _ \| __/ _ \/ __| __|  \___ \   / /\ \    
    | |  | | |_| | (_) | ||  __/\__ \ |_   ____) | / ____ \ _ 
    |_|  |_|\__, |\___/ \__\___||___/\__| |_____(_)_/    \_(_)
             __/ |                                            
            |___/                                             
*
* Copyright (c) 2004-2016 Myotest SA
*
* PackageLicenseDeclared: Apache-2.0 
* 
* Licensed under the Apache License, Version 2.0 (the "License"); 
* you may not use this file except in compliance with the License. 
* You may obtain a copy of the License at 
* 
*     http://www.apache.org/licenses/LICENSE-2.0 
* 
* Unless required by applicable law or agreed to in writing, software 
* distributed under the License is distributed on an "AS IS" BASIS, 
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
* See the License for the specific language governing permissions and 
* limitations under the License. 
****************************************************************************/

#ifndef __UIF_UI_MYOTEST_STEP_ANALYSIS_TABLE_H__
#define __UIF_UI_MYOTEST_STEP_ANALYSIS_TABLE_H__

#include "UIFramework/UIView.h"
#include "UIFramework/UITextMonitorView.h"
#include "UIFramework/UITextView.h"

#include "core-util/SharedPointer.h"

#include "myotest-step-analysis-library/wrd_public.h"

class StepAnalysisTable : public UIView::Array
{
public:
    virtual uint32_t getSize(void) const;
    virtual SharedPointer<UIView> viewAtIndex(uint32_t index) const;
    virtual uint32_t heightAtIndex(uint32_t index) const;
    virtual uint32_t widthAtIndex(uint32_t index) const;

    virtual const char* getTitle(void) const;
    virtual uint32_t getFirstIndex(void) const;
    virtual uint32_t getLastIndex(void) const;
    virtual uint32_t getDefaultIndex(void) const;

    virtual SharedPointer<UIView::Action> actionAtIndex(uint32_t index);
};

#endif // __UIF_UI_MYOTEST_STEP_ANALYSIS_TABLE_H__
