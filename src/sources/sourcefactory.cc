#include "sourcefactory.h"

#include "noisewave.h"
#include "netdatawave.h"
#include "netdataraw.h"


pISource_t SourceFactory::create(std::string typname, pSourceState_t ss) {
  
  std::string defaultname = "sourcename"; 
  
  if (typname == NoiseWave::TYPENAME) {
    pNoiseWave_t nw(new NoiseWave(defaultname, ss->timer)); 
    return nw; 

  } else if (typname == NetDataWave::TYPENAME) {
    pNetDataWave_t ndw(new NetDataWave(defaultname, ss->timer, ss->netdatacache, 
				       ss->somanetcodec)); 
    return ndw; 
  } else if (typname == NetDataRaw::TYPENAME) {
    pNetDataRaw_t ndw(new NetDataRaw(defaultname, ss->timer, ss->netdatacache, 
				       ss->somanetcodec)); 
    return ndw; 
  } else {
    throw std::runtime_error("Unknown source type " + typname); 
  }

}
