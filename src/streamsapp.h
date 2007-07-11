#include <iostream>
#include <cstdlib>
#include <cmath>
#include <set>
#include <assert.h>

#include <stdlib.h>
#include <gtkmm.h>

#define GL_GLEXT_PROTOTYPES
#include <gtkglmm.h>

#ifdef G_OS_WIN32
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>

#include "glspikes.h"
#include "wavewin.h"
#include "wavestreamsource.h"
#include "wavestreamvis.h"
#include "wavestreamvisstatus.h"
#include "triggerwin.h"
#include "streamcontrol.h" 
#include "sourcestatus.h"
#include "visproperty.h"


class StreamsApp : public Gtk::Window
{
public:
   explicit StreamsApp(bool is_sync = true); 
   virtual ~StreamsApp(); 

protected:

   Glib::RefPtr<Gtk::ActionGroup> pActionGroup_;

   Glib::RefPtr<Gtk::UIManager> pUIManager_;
   
   // widgets
   Gtk::VBox  vBoxMain_; 
   Gtk::HBox  hBoxMain_; 
   Gtk::HBox  hBoxStatus_; 
   Gtk::VBox  vBoxStreamStatus_; 
   Gtk::Widget* pMenuBar_; 
   Gtk::Statusbar statusBar_; 
   Gtk::ToggleButton liveButton_; 
   Gtk::ProgressBar statusProgressBar_; 
   // stream source widgets
   std::vector<SourceStatus * >  pSourceStatusWidgets_; 
   std::vector<VisStatus *  >  pVisStatusWidgets_; 
   
   
   void buildActions(); 
   void newStreamSource(std::string name); 
   void newStreamVis(SourceStatus *, std::string name); 
   void newStreamVis1(std::string name); 
   
   
  // signal handlers:
/*   void on_button_quit_clicked(); */
/*   virtual bool on_idle(); */

   StreamControl streamControl_; 
   
   std::set<streamVisPtr_t> streamVisSelSet_; 


   WaveWin waveWin_; 
   TriggerWin triggerWin_; 


  //sigc::connection conn_; 
  //waveStreamVisStatusSet_t wsvsSelSet_; 
   void svSelSetModify(bool append, streamVisPtr_t v); 
   VisProperty visProperty_;


};

