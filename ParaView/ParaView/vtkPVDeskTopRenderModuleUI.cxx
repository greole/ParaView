/*=========================================================================

  Program:   ParaView
  Module:    vtkPVDeskTopRenderModuleUI.cxx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

Copyright (c) 2000-2001 Kitware Inc. 469 Clifton Corporate Parkway,
Clifton Park, NY, 12065, USA.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

 * Neither the name of Kitware nor the names of any contributors may be used
   to endorse or promote products derived from this software without specific 
   prior written permission.

 * Modified source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/
#include "vtkPVDeskTopRenderModuleUI.h"
#include "vtkPVDeskTopRenderModule.h"
#include "vtkObjectFactory.h"
#include "vtkKWLabel.h"
#include "vtkKWCheckButton.h"
#include "vtkKWScale.h"
#include "vtkPVApplication.h"
#include "vtkTimerLog.h"
#include "vtkKWLabeledFrame.h"


//----------------------------------------------------------------------------
vtkStandardNewMacro(vtkPVDeskTopRenderModuleUI);
vtkCxxRevisionMacro(vtkPVDeskTopRenderModuleUI, "1.2");

int vtkPVDeskTopRenderModuleUICommand(ClientData cd, Tcl_Interp *interp,
                             int argc, char *argv[]);


//----------------------------------------------------------------------------
vtkPVDeskTopRenderModuleUI::vtkPVDeskTopRenderModuleUI()
{
  this->CommandFunction = vtkPVDeskTopRenderModuleUICommand;
}


//----------------------------------------------------------------------------
vtkPVDeskTopRenderModuleUI::~vtkPVDeskTopRenderModuleUI()
{
}

//----------------------------------------------------------------------------
void vtkPVDeskTopRenderModuleUI::Create(vtkKWApplication *app, const char *)
{
  vtkPVApplication *pvapp = vtkPVApplication::SafeDownCast(app);
  // Skip over LOD res and threshold.
  
  if (this->Application)
    {
    vtkErrorMacro("RenderModuleUI already created");
    return;
    }

  this->Superclass::Create(app, NULL);

  this->Script("pack forget %s",
               this->ParallelRenderParametersFrame->GetWidgetName());
  //this->CompositeCompressionCheck->EnabledOff();

  //this->SquirtCheck->SetState(0);
  //this->SquirtLabel->EnabledOff();
  //this->SquirtCheck->EnabledOff();
  //this->SquirtLevelScale->EnabledOff();
  //this->SquirtLevelLabel->EnabledOff();

  this->SetReductionFactor(1);
  this->ReductionCheck->EnabledOff();
  this->ReductionLabel->EnabledOff();

}

//----------------------------------------------------------------------------
void vtkPVDeskTopRenderModuleUI::EnableRenductionFactor()
{
  this->SetReductionFactor(2);
  this->ReductionCheck->EnabledOn();
  this->ReductionLabel->EnabledOn();

}





//----------------------------------------------------------------------------
void vtkPVDeskTopRenderModuleUI::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
}

