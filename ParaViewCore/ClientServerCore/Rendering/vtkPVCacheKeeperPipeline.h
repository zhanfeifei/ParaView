/*=========================================================================

  Program:   ParaView
  Module:    vtkPVCacheKeeperPipeline.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkPVCacheKeeperPipeline
// .SECTION Description
//

#ifndef vtkPVCacheKeeperPipeline_h
#define vtkPVCacheKeeperPipeline_h

#include "vtkPVClientServerCoreRenderingModule.h" //needed for exports
#include "vtkCompositeDataPipeline.h"

class vtkPVCacheKeeper;
class VTKPVCLIENTSERVERCORERENDERING_EXPORT vtkPVCacheKeeperPipeline : public vtkCompositeDataPipeline
{
public:
  static vtkPVCacheKeeperPipeline* New();
  vtkTypeMacro(vtkPVCacheKeeperPipeline, vtkCompositeDataPipeline);
  void PrintSelf(ostream& os, vtkIndent indent);

protected:
  vtkPVCacheKeeperPipeline();
  ~vtkPVCacheKeeperPipeline();

  virtual int ForwardUpstream(int i, int j, vtkInformation* request);
  virtual int ForwardUpstream(vtkInformation* request);
private:
  vtkPVCacheKeeperPipeline(const vtkPVCacheKeeperPipeline&); // Not implemented
  void operator=(const vtkPVCacheKeeperPipeline&); // Not implemented

};

#endif

