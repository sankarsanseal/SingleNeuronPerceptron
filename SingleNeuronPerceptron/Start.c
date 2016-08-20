/*
 * Start.c
 *
 *  Created on: 12 আগস্ট, 2016
 *      Author: sankarsan
 */
#include <mgl2/mgl_cf.h>



int sample(HMGL * gr)
{
  //HMDT y;  mgls_prepare1d(&y);
  //gr->SetOrigin(0,0,0);
  //gr->SubPlot(2,2,0,"");  gr->Title("Plot plot (default)");
  //gr->Box();  gr->Plot(y);


 /* mgl_set_origin(*gr,0,0,0);
  mgl_subplot(*gr,2,2,0,"");
  mgl_title(*gr,"Plot plot (default)");
  mgl_box(*gr);
  mgl_plot(gr,&y,NULL);
  return 0;*/

  HMDT y = mgl_create_data_size(50,3,1);
  char pen='x',opt='o';
  mgl_data_modify(y,"0.7*sin(2*pi*x) + 0.5*cos(3*pi*x) + 0.2*sin(pi*x)",0);
  mgl_data_modify(y,"sin(2*pi*x)",1);
  mgl_data_modify(y,"cos(2*pi*x)",2);
  mgl_box(*gr);
  mgl_plot(*gr,y,&pen,&opt);
  mgl_delete_data(y);
  return 0;
}



int main()
{
  HMGL gr;
  gr=mgl_create_graph(640, 480);
  sample (&gr);



  // mgl_write_frame(gr,"test.png","");
 // mgl_delete_graph(gr);
}

