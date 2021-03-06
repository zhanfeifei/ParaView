/*=========================================================================

  Program:   ParaView
  Module:    vtkGeometrySliceRepresentation.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkGeometrySliceRepresentation - extends vtkGeometryRepresentation to
// add support for showing just specific slices from the dataset.
// .SECTION Description
// vtkGeometrySliceRepresentation extends vtkGeometryRepresentation to show
// slices from the dataset. This is used for vtkPVMultiSliceView and
// vtkPVOrthographicSliceView.

#ifndef vtkGeometrySliceRepresentation_h
#define vtkGeometrySliceRepresentation_h

#include "vtkGeometryRepresentation.h"

class VTKPVCLIENTSERVERCORERENDERING_EXPORT vtkGeometrySliceRepresentation : public vtkGeometryRepresentation
{
public:
  static vtkGeometrySliceRepresentation* New();
  vtkTypeMacro(vtkGeometrySliceRepresentation, vtkGeometryRepresentation);
  void PrintSelf(ostream& os, vtkIndent indent);

  virtual int ProcessViewRequest(
    vtkInformationRequestKey* request_type,
    vtkInformation* inInfo, vtkInformation* outInfo);

  enum
    {
    X_SLICE_ONLY,
    Y_SLICE_ONLY,
    Z_SLICE_ONLY,
    ALL_SLICES
    };
  vtkSetClampMacro(Mode, int, X_SLICE_ONLY, ALL_SLICES);
  vtkGetMacro(Mode, int);

  // Description:
  // Get/Set whether original data outline should be shown in the view.
  vtkSetMacro(ShowOutline, bool);
  vtkGetMacro(ShowOutline, bool);

protected:
  vtkGeometrySliceRepresentation();
  ~vtkGeometrySliceRepresentation();

  virtual void SetupDefaults();
  virtual int RequestData(vtkInformation* request,
    vtkInformationVector** inputVector, vtkInformationVector* outputVector);

  virtual bool AddToView(vtkView* view);
  virtual bool RemoveFromView(vtkView* view);
private:
  vtkGeometrySliceRepresentation(const vtkGeometrySliceRepresentation&); // Not implemented
  void operator=(const vtkGeometrySliceRepresentation&); // Not implemented

  class vtkInternals;
  vtkInternals* Internals;
  int Mode;
  bool ShowOutline;

};

#endif
