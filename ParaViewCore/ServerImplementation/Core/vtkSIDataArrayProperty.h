/*=========================================================================

  Program:   ParaView
  Module:    vtkSIDataArrayProperty.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkSIDataArrayProperty - InformationOnly property
// .SECTION Description
// SIProperty that deals with vtkDataArray object type

#ifndef vtkSIDataArrayProperty_h
#define vtkSIDataArrayProperty_h

#include "vtkPVServerImplementationCoreModule.h" //needed for exports
#include "vtkSIProperty.h"

class VTKPVSERVERIMPLEMENTATIONCORE_EXPORT vtkSIDataArrayProperty : public vtkSIProperty
{
public:
  static vtkSIDataArrayProperty* New();
  vtkTypeMacro(vtkSIDataArrayProperty, vtkSIProperty);
  void PrintSelf(ostream& os, vtkIndent indent);

protected:
  vtkSIDataArrayProperty();
  ~vtkSIDataArrayProperty();

  friend class vtkSIProxy;

  // Description:
  // Pull the current state of the underneath implementation
  virtual bool Pull(vtkSMMessage*);

private:
  vtkSIDataArrayProperty(const vtkSIDataArrayProperty&); // Not implemented
  void operator=(const vtkSIDataArrayProperty&); // Not implemented

};

#endif
