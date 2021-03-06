#ifndef VISSTATUS_H
#define VISSTATUS_H

#include <gtkmm.h>
#include "streams.h"
#include "streamvis.h"

class VisStatus : public Gtk::HBox
{
 public: 

  // emit a selected signal
  sigc::signal<void, bool> clickedSignal() {
    return clickedSignal_; 
  }
  
  virtual pStreamVisBase_t getVisPtr() = 0; 
  virtual void setSelected(bool state) = 0; 

 private:

  sigc::signal<void, bool> clickedSignal_; 
  
};


#endif // VISSTATUS_H
