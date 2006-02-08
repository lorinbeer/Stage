/*
 *  Player - One Hell of a Robot Server
 *  Copyright (C) 2004, 2005 Richard Vaughan
 *                      
 * 
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/*
 * Desc: A plugin driver for Player that gives access to Stage devices.
 * Author: Richard Vaughan
 * Date: 10 December 2004
 * CVS: $Id: p_graphics2d.cc,v 1.1 2006-02-08 08:53:54 rtv Exp $
 */

#include "p_driver.h"

#include <iostream>
using namespace std;

// DOCUMENTATION ------------------------------------------------------------

/** @addtogroup player 
@par Graphics2d interface
- PLAYER_GRAPHICS2D_CMD_CLEAR
- PLAYER_GRAPHICS2D_CMD_POINTS
*/


InterfaceGraphics2d::InterfaceGraphics2d( player_devaddr_t addr, 
			    StgDriver* driver,
			    ConfigFile* cf,
			    int section )
  : InterfaceModel( addr, driver, cf, section, NULL )
{ 
  // get or create a nice clean figure for drawing
  this->fig = stg_model_get_fig( mod, "g2d_fig" );
  
  if( ! this->fig )
    this->fig = stg_model_fig_create( mod, "g2d_fig", "top", 99 );
  
  stg_rtk_fig_clear( this->fig );
}

InterfaceGraphics2d::~InterfaceGraphics2d( void )
{ 
  stg_rtk_fig_clear( this->fig );
};


int InterfaceGraphics2d::ProcessMessage(MessageQueue* resp_queue,
				 player_msghdr_t* hdr,
				 void* data)
{
  // printf( "Stage graphics2d interface processing message\n" );
  
  if(Message::MatchMessage(hdr, PLAYER_MSGTYPE_CMD, 
                           PLAYER_GRAPHICS2D_CMD_CLEAR, 
                           this->addr))
    {
      stg_rtk_fig_clear( this->fig );
      
      return 0; //ok
    }
  
  if(Message::MatchMessage(hdr, PLAYER_MSGTYPE_CMD, 
                           PLAYER_GRAPHICS2D_CMD_POINTS, 
                           this->addr))
    {
      player_graphics2d_cmd_points_t* pcmd = 
	(player_graphics2d_cmd_points_t*)data;
      
      unsigned int col=0;
      col = pcmd->color.red << 16;
      col += pcmd->color.green << 8;
      col += pcmd->color.blue;

      stg_rtk_fig_color_rgb32( this->fig, col );
      
      for( int p=0; p<pcmd->count; p++ )	
	{
	  //printf( "Drawing point %.2f %.2f\n", pcmd->points[p].px, pcmd->points[p].py );
	  stg_rtk_fig_point( this->fig, 
			     pcmd->points[p].px, 
			     pcmd->points[p].py );      
	}
      return 0; //ok
    }

  
  PLAYER_WARN2("stage graphics2d doesn't support message %d:%d.", 
	       hdr->type, hdr->subtype );
  return -1;
}