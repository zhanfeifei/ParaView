/*=========================================================================

  Program:   ParaView
  Module:    vtkSMPipelineState.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkSMPipelineState - class that manage the state of the processing
// pipeline
// .SECTION Description
// This class is used to provide a RemoteObject API to the vtkSMProxyManager
// which allow Undo/Redo and state sharing across several ParaView clients.
// Basically, we expose the state management API of RemoteObject to handle
// registration and unregistration of proxies.

#ifndef vtkSMPipelineState_h
#define vtkSMPipelineState_h

#include "vtkPVServerManagerCoreModule.h" //needed for exports
#include "vtkSMRemoteObject.h"
#include "vtkSMMessageMinimal.h" // needed for vtkSMMessage
#include "vtkWeakPointer.h" // needed for vtkWeakPointer

class vtkSMSession;
class vtkSMProxyLocator;

class VTKPVSERVERMANAGERCORE_EXPORT vtkSMPipelineState : public vtkSMRemoteObject
{
  // My friends are...
  friend class vtkSMSessionProxyManager;

public:
  static vtkSMPipelineState* New();
  vtkTypeMacro(vtkSMPipelineState,vtkSMRemoteObject);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // This method return the full object state that can be used to create that
  // object from scratch.
  // This method will be used to fill the undo stack.
  // If not overriden this will return NULL.
  virtual const vtkSMMessage* GetFullState();

  // Description:
  // This method is used to initialise the object to the given state
  virtual void LoadState( const vtkSMMessage* msg, vtkSMProxyLocator* locator);

  void ValidateState();

protected:
  // Description:
  // Default constructor.
  vtkSMPipelineState();

  // Description:
  // Destructor.
  virtual ~vtkSMPipelineState();

private:
  vtkSMPipelineState(const vtkSMPipelineState&); // Not implemented
  void operator=(const vtkSMPipelineState&);       // Not implemented

};

#endif // #ifndef vtkSMPipelineState_h
