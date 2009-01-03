#include <boost/format.hpp>

#include "netdatawavewidget.h"


NetDataWaveWidget::NetDataWaveWidget(NetDataWave * nw) :
  ElementStatus(), 
  netDataWave_(nw)
{
  add(vboxMain_); 
  vboxMain_.pack_start(hboxAnalog_); 
  
  hboxAnalog_.pack_start(vboxSource_); 

  labelSource_.set_label("src"); 
  vboxSource_.pack_start(labelSource_); 
  labelSourceValue_.set_use_markup(true); 
  vboxSource_.pack_start(labelSourceValue_); 

  hboxAnalog_.pack_start(analogProps_); 

  analogProps_.pack_start(hboxGain_); 
  hboxGain_.pack_start(labelGain_); 
  labelGain_.set_label("gain:"); 
  hboxGain_.pack_start(labelGainValue_); 

  analogProps_.pack_start(hboxHPF_); 
  hboxHPF_.pack_start(labelHPF_); 
  hboxHPF_.pack_start(labelHPFValue_); 
  labelHPF_.set_label("HP Filter"); 

  show_all(); 

  sourceCallback(0); 
  netDataWave_->src.signal().connect(sigc::mem_fun(*this, 
						  &NetDataWaveWidget::sourceCallback)); 
  gainCallback(0); 
  netDataWave_->gain.signal().connect(sigc::mem_fun(*this, 
						    &NetDataWaveWidget::gainCallback)); 
    
  hpfCallback(false); 
  netDataWave_->hpfen.signal().connect(sigc::mem_fun(*this, 
						     &NetDataWaveWidget::hpfCallback)); 
  
}


NetDataWaveWidget::~NetDataWaveWidget()
{
  
  
}

void NetDataWaveWidget::sourceCallback(int src)
{
  std::string txt = boost::str(boost::format("<big><big><big><big><big><big><big>%d</big></big></big></big></big></big></big>") % (int)netDataWave_->src); 
  labelSourceValue_.set_label(txt); 
}

void NetDataWaveWidget::gainCallback(int gain)
{
  std::string txt = boost::str(boost::format("%d") % (int)netDataWave_->gain); 
  labelGainValue_.set_label(txt); 
  
}


void NetDataWaveWidget::hpfCallback(bool hpf)
{
  if (netDataWave_->hpfen) {
    labelHPFValue_.set_label("enabled"); 
  } else {
    labelHPFValue_.set_label("disabled"); 
  }
  
}
