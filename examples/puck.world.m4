include(robots.m4)

set environment_file = rink.pnm
set pixels_per_meter = 80
set laser_res = 2

# these servers enable clients (e.g. xs) access to Stage's internal models
enable truth_server
enable environment_server

forager(3.48223304703,3.48223304703,0,6665)
forager(6.51776695296,3.48223304703,0,6666)
forager(3.48223304703,6.51776695296,0,6667)
forager(6.51776695296,6.51776695296,0,6668)
create movable_object pose 2.72334957055 2.72334957055 0 friction 0.035 
create movable_object pose 4.24111652352 2.72334957055 0 friction 0.035
create movable_object pose 5.75888347649 2.72334957055 0 friction 0.035
create movable_object pose 7.27665042946 2.72334957055 0 friction 0.035
create movable_object pose 2.72334957055 4.24111652352 0 friction 0.035
create movable_object pose 4.24111652352 4.24111652352 0 friction 0.035
create movable_object pose 5.75888347649 4.24111652352 0 friction 0.035
create movable_object pose 7.27665042946 4.24111652352 0 friction 0.035
create movable_object pose 2.72334957055 5.75888347649 0 friction 0.035
create movable_object pose 4.24111652352 5.75888347649 0 friction 0.035
create movable_object pose 5.75888347649 5.75888347649 0 friction 0.035
create movable_object pose 7.27665042946 5.75888347649 0 friction 0.035
create movable_object pose 2.72334957055 7.27665042946 0 friction 0.035
create movable_object pose 4.24111652352 7.27665042946 0 friction 0.035
create movable_object pose 5.75888347649 7.27665042946 0 friction 0.035
create movable_object pose 7.27665042946 7.27665042946 0 friction 0.035