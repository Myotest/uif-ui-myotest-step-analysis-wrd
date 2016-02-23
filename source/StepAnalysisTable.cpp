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

#include "uif-ui-myotest-step-analysis-wrd/StepAnalysisTable.h"

typedef enum {
    CELL_TOP_FILLER = 0,
    CELL_WALKING_STEPS_TITLE,
    CELL_MID_FILLER_1,
    CELL_WALKING_STEPS_VALUE,
    CELL_MID_FILLER_2,
    CELL_RUNNING_STEPS_TITLE,
    CELL_MID_FILLER_3,
    CELL_RUNNING_STEPS_VALUE,
    CELL_END_FILLER
} entries_t;

SharedPointer<UIView> StepAnalysisTable::viewAtIndex(uint32_t index) const
{
    UIView* cell = NULL;

    UITextMonitorView<int32_t>* textMonitorViewWalkStep = NULL;
    UITextMonitorView<int32_t>* textMonitorViewRunStep = NULL;

    switch(index)
    {
        case CELL_WALKING_STEPS_TITLE:
                            cell = new UITextView("walking steps", &Font_Breadcrumbs);
                            break;

        case CELL_WALKING_STEPS_VALUE:
                            textMonitorViewWalkStep = new UITextMonitorView<int32_t>(&myoAPI_getWalkingStepCounter,"%4d", &Font_Menu, 100);
                            cell = (UITextView*)textMonitorViewWalkStep;
                            break;

        case CELL_RUNNING_STEPS_TITLE:
                            cell = new UITextView("running steps", &Font_Breadcrumbs);
                            break;

        case CELL_RUNNING_STEPS_VALUE:
                            textMonitorViewRunStep = new UITextMonitorView<int32_t>(&myoAPI_getRunningStepCounter,"%4d", &Font_Menu, 100);
                            cell = (UITextView*)textMonitorViewRunStep;
                            break;

        case CELL_TOP_FILLER:
        case CELL_MID_FILLER_1:
        case CELL_MID_FILLER_2:
        case CELL_MID_FILLER_3:
        case CELL_END_FILLER:
        default:
                            cell = new UIImageView(NULL);
                            break;
    }

    if (cell)
    {
        cell->setHorizontalAlignment(UIView::ALIGN_CENTER);
        cell->setVerticalAlignment(UIView::VALIGN_MIDDLE);
        cell->setWidth(0);
        cell->setHeight(0);
    }

    return SharedPointer<UIView>(cell);
}

uint32_t StepAnalysisTable::getSize() const
{
    return CELL_END_FILLER + 1;
}

uint32_t StepAnalysisTable::widthAtIndex(uint32_t index) const
{
    (void) index;

    return 128;
}

uint32_t StepAnalysisTable::heightAtIndex(uint32_t index) const
{
    uint32_t ret = 0;

    switch(index)
    {
        case CELL_WALKING_STEPS_TITLE:
        case CELL_RUNNING_STEPS_TITLE:
                                ret = 7;
                                break;

        case CELL_WALKING_STEPS_VALUE:
                                ret = 31;
                                break;

        case CELL_RUNNING_STEPS_VALUE:
                                ret = 25;
                                break;

        case CELL_TOP_FILLER:
                                ret = 24; // 11 + 13
                                break;

        case CELL_MID_FILLER_1:
        case CELL_MID_FILLER_2:
        case CELL_MID_FILLER_3:
                                ret = 6;
                                break;

        case CELL_END_FILLER:
                                ret = 16; // 11 + 5
                                break;
        default:
                                ret = 0;
                                break;
    }

    return ret;
}

SharedPointer<UIView::Action> StepAnalysisTable::actionAtIndex(uint32_t index)
{
    (void) index;

    SharedPointer<UIView::Action> returnObject(new UIView::Action);

    return returnObject;
}

const char* StepAnalysisTable::getTitle() const
{
    return "step analysis";
}

uint32_t StepAnalysisTable::getFirstIndex() const
{
    return CELL_TOP_FILLER;
}

uint32_t StepAnalysisTable::getLastIndex() const
{
    return CELL_END_FILLER;
}

uint32_t StepAnalysisTable::getDefaultIndex() const
{
    return CELL_TOP_FILLER;
}
