#ifndef STREAMPIPELINE_H
#define STREAMPIPELINE_H

#include <list>
#include "forward.h"

#include "isource.h"
#include "ifilter.h"
#include "itrigger.h"
#include "ivis.h"

#include "sourcestate.h" 
#include "isourcevisitor.h"
#include "ifiltervisitor.h"
#include "itriggervisitor.h"
#include "ivisvisitor.h"

class StreamPipeline {
public:
  StreamPipeline(std::string name, pSourceState_t sourceState, 
		 pISourceVisitor_t,  pIFilterVisitor_t, 
		 pITriggerVisitor_t, pIVisVisitor_t ); 
  
  ~StreamPipeline(); 
  
  void resetVisitors(pISourceVisitor_t, pIFilterVisitor_t, 
		     pITriggerVisitor_t, pIVisVisitor_t); 
  
  pISource_t createSource(std::string type, std::string name); 
  pIFilter_t createFilter(std::string type, std::string name); 
  pITrigger_t createTrigger(std::string type, std::string name); 
  pIVis_t createVis(std::string type, std::string vis); 
  
  std::list<pISource_t> getSources(); 
  std::list<pIFilter_t> getFilters(); 
  std::list<pITrigger_t> getTriggers(); 
  std::list<pIVis_t> getVis(); 
  std::string getName() {return name_;}

private:
  
  pSourceState_t pSourceState_;       

  std::list<pISource_t> sources_; 
  std::list<pIFilter_t> filters_;  
  std::list<pITrigger_t> triggers_; 
  std::list<pIVis_t> vis_; 
  
  pISourceVisitor_t sourceVisitor_; 
  pIFilterVisitor_t filterVisitor_; 
  pITriggerVisitor_t triggerVisitor_; 
  pIVisVisitor_t  visVisitor_; 
  
  void setSource(pISource_t src); 
  void addFilter(pIFilter_t filter); 
  void addTrigger(pITrigger_t trigger); 
  void addVis(pIVis_t vis); 
  
  // callbacks for destruction ! 
  void destroySource(); 

  std::string name_; 
}; 

typedef boost::shared_ptr<StreamPipeline> pStreamPipeline_t; 


#endif // STREAMPIPELINE_H

