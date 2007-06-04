/* Conversion to gtkglextmm by Naofumi Yasufuku */

#include <iostream>
#include <cstdlib>
#include <cmath>
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
#include "wave.h"


class Vis : public Gtk::Window
{
public:
  explicit Vis(bool is_sync = true);
  virtual ~Vis();

protected:
  // signal handlers:
  void on_button_quit_clicked();
  virtual bool on_idle();

protected:
  // member widgets:
  Gtk::VBox m_VBox;
  Glib::Timer timer_; 
  Glib::Timer dtimer_; 
  Gtk::Button m_ButtonQuit;
  WaveWin waveWin_; 
  uint64_t lastSpikeTime_; 
  void updateSpikePosFromAdj(); 
  sigc::connection m_ConnectionIdle;
  virtual bool on_key_press_event(GdkEventKey* event); 
  std::vector<WaveRenderer *>  wrs; 

};

Vis::Vis(bool is_sync)
  : m_VBox(false, 0), 
    m_ButtonQuit("Quit"), 
    waveWin_(),
    lastSpikeTime_(0)
{

  set_title("Vis");

  // Get automatically redrawn if any of their children changed allocation.
  set_reallocate_redraws(true);

  add(m_VBox);

  //
  // Vis scene.
  //
  waveWin_.set_size_request(1000, 400);

//   for (int i = 0; i < 10000; i++)
//     {
//       waveWin_.appendRate(float(i)/1000.0); 
//     }
  
  
  //
  // Simple quit button.
  //

  m_ButtonQuit.signal_clicked().connect(
    sigc::mem_fun(*this, &Vis::on_button_quit_clicked));
  
  m_VBox.pack_start(waveWin_); 
  m_VBox.pack_start(m_ButtonQuit, Gtk::PACK_SHRINK, 0);

  show_all();

  Glib::signal_idle().connect( sigc::mem_fun(*this, &Vis::on_idle) );
  timer_.start(); 
  dtimer_.start(); 

  // generate N wave renderers:
  for (int i = 0; i < 10; i++)
    {
      WaveRenderer * pwr = new WaveRenderer(); 
      wrs.push_back(pwr); 
      waveWin_.appendRenderer(pwr); 

      pwr->newTriggers().connect(sigc::mem_fun(pwr, 
					       &WaveRenderer::appendTriggers) ); 
      pwr->generateFakeData(); 
    }

  //Glib::signal_idle().connect( sigc::mem_fun(*this, &TSpikeWin::on_idle) );


}

Vis::~Vis()
{
}

void Vis::on_button_quit_clicked()
{
  // we should quit
}

bool Vis::on_key_press_event(GdkEventKey* event)
{
  std::cout << "Keypress" << std::endl; 
  switch (event->keyval)
    {
    case GDK_z:
      break;
    case GDK_Z:
      break;
    case GDK_Up:
      std::cout << "Changing zoom" << std::endl; 
      break;
    case GDK_Down: 
      std::cout << "Changing zoom down" << std::endl; 
      break; 
    default:
      break;
    }
  return true; 

}


bool Vis::on_idle()

{

  double seconds = timer_.elapsed();
  
  if (seconds >= 1.00)
    {
      timer_.reset();
    }

  
  return true;
}


void spikeWaves(void)
{

  

} 

int main(int argc, char** argv)
{
  Gtk::Main kit(argc, argv);

  //
  // Init gtkglextmm.
  //

  Gtk::GL::init(argc, argv);

  
  Vis vis(true);

  kit.run(vis);

  return 0;
}
