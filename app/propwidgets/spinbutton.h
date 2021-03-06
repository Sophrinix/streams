#ifndef PROPERTY_SPINBUTTON_H
#define PROPERTY_SPINBUTTON_H

#include <gtkmm.h>
#include <properties.h>
#include <set>
#include <list>

namespace PropertyWidgets
{
  class SpinButton : public Gtk::SpinButton 
  {
  public:
    SpinButton(Gtk::Adjustment & adj); 
    ~SpinButton(); 
    enum State {NORMAL, PENDING, CONFLICTED}; 

  public:
    typedef Property<float> *  pProperty_t; 
    void addProperty(pProperty_t spinProperty); 
    void delProperty(pProperty_t  spinProperty); 
    
  private:
    typedef std::set<pProperty_t >  propset_t ; 
    typedef std::map<pProperty_t, sigc::connection>  sigconnmap_t; 
    propset_t propertySet_; 
    sigconnmap_t connMap_; 
    void refreshProperty(float value); 

    State state_; 
    float value_; 
    void setState(State); 
    void on_my_value_changed(); 

  }; 
  
}

#endif // SPINBUTTON_H
