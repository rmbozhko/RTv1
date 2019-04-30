#include "rtv1.h"

t_matrix matrix_creation(float x, float y, float z)
{
	t_matrix matrix;

	matrix.ab = x;
	matrix.ord = y;
	matrix.apl = z;
	return (vector);
}

t_list_obj	*create_entity(void *obj, int type)
{
	t_list_obj *node;

	node = (t_list_obj *)malloc(sizeof(t_list_obj));
	node->obj = obj;
	node->type = type;
	node->next = NULL;
	return (node);
}

void add_entity(t_list_obj **head, t_list_obj *node)
{
	t_list_obj *tmp;

	tmp = *head;
	if (tmp == NULL)
	{
		*head = node;
	}
	else
	{		
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;		
	}
}

t_tdparaleg *tdparaleg_creation(t_matrix loc, t_matrix norm, float rad, t_paint paint)
{
	t_tdparaleg *tdparaleg;

	tdparaleg = malloc(sizeof(t_tdparaleg));
	if (tdparaleg == NULL)
		close_app("Cylinder is not created", 0);
	tdparaleg->location = loc;
	tdparaleg->coord_move = norm;
	tdparaleg->div_diameter = rad;
	tdparaleg->paint = paint;	
	return (tdparaleg);
}

t_trg *trg_creation(t_matrix loc, t_matrix norm, t_paint paint)
{
	t_trg *trg;

	trg = malloc(sizeof(t_trg));
	if (trg == NULL)
		close_app("Cone is not created", 0);
	cone->location = loc;
	cone->coord_move = norm;
	cone->paint = color;
	cone->corner = ANGLE;
	return (cone);
}

t_surface *surface_creation(t_matrix loc, t_matrix norm, t_paint paint)
{
	t_surface *surface;

	surface = malloc(sizeof(t_surface));
	if (surface == NULL)
		close_app("Plane is not created", 0);
	surface->dot = loc;
	surface->optimize_rate = norm;
	surface->paint = paint;
	return (surface);
}

t_tdcircle *tdcircle_creation(t_matrix loc, t_paint paint, float rad)
{
	t_tdcircle *sphere;

	sphere = malloc(sizeof(t_sphere));
	if (sphere == NULL)
		close_app("Sphere is not created", 0);
	sphere->location = loc;
	sphere->paint = paint;
	sphere->div_diameter = rad;
	return (sphere);
}

void init_scene_1(t_env *env)
{
	t_entity 	*entity_list;

	entity_list = NULL;
	add_entity(&entity_list,
		create_entity(create_sphere(matrix_creation(0, 0, 0), (t_paint){1, 0, 0}, 300), SPHERE));
	add_entity(&entity_list,
		create_entity(create_sphere(matrix_creation(600, 100, 400), (t_paint){1, 0, 0}, 300), SPHERE));
	add_entity(&entity_list,
		create_entity(create_cylinder(matrix_creation(300, 0, 300), matrix_creation(0,1,0),100, (t_paint){0,0,1}), CYLINDER));
	add_entity(&entity_list,
		create_entity(create_cylinder(matrix_creation(600, 0, 300), matrix_creation(0.5,0.5,0),100, (t_paint){0,0,1}), CYLINDER));
	add_entity(&entity_list,
		create_entity(create_plane(matrix_creation(0, 900, 0), matrix_creation(0, -1, 0),(t_paint){0.6, 0.6, 0.7}), PLANE));
	add_entity(&entity_list,
		create_entity(create_cone(matrix_creation(200,0,0), matrix_creation(0,1,0), (t_paint){1,1,0}, 30) ,CONE));
	add_entity(&entity_list,
		create_entity(create_plane(matrix_creation(0, -100, 0),matrix_creation(0, 0, 1),(t_paint){0, 1, 0}), PLANE));
	env->start_entity = entity_list;
}

// void init_scene_2(t_scene *scene)
// {
// 	t_list_obj *obj;
// 	t_light *lights;

// 	obj = NULL;
// 	lights = NULL;	
// 	add_node_light(&lights,create_light(create_vector(800, 600, 800),
// 		(t_color){0.8, 0.8, 0.8}, 20));
// 	add_entity(&obj,create_node_obj(create_plane(create_vector(0, 0, -1000),
// 		create_vector(0, 0, 1),(t_color){0.7, 0.5, 0.5}), PLANE));
// 	add_entity(&obj,create_node_obj(create_plane(create_vector(0, -1000, 0),
// 		create_vector(0, 0.5, 0.1),(t_color){0.6, 0.6, 0.7}), PLANE));
// 	add_entity(&obj,create_node_obj(create_plane(create_vector(-1000, 0, 0),
// 		create_vector(1, -1, 0),(t_color){0.3, 0, 0.7}), PLANE));
// 	add_entity(&obj,create_node_obj(create_plane(create_vector(3000, 0, 0),
// 		create_vector(1, 1, 0),(t_color){0, 0.3, 0.7}), PLANE));
// 	add_entity(&obj,create_node_obj(create_cylinder(create_vector(300,0,300),
// 		create_vector(0,1,0),100, (t_color){0,0,1}), CYLINDER));
// 	add_entity(&obj,create_node_obj(create_cylinder(create_vector(1500,0,300),
// 		create_vector(0,1,0),100, (t_color){0,0,1}), CYLINDER));
// 	add_entity(&obj,create_node_obj(create_cylinder(create_vector(900,
// 		0, -300), create_vector(0,1,0),100, (t_color){0,0,1}), CYLINDER));
// 	scene->obj = obj;
// 	scene->lights = lights;
// }

// void init_scene_3(t_scene *scene)
// {
// 	t_list_obj *obj;
// 	t_light *lights;

// 	obj = NULL;
// 	lights = NULL;
// 	add_node_light(&lights,create_light(create_vector(1500, 600, -500),
// 		(t_color){0.8, 0.8, 0.8}, 20));
// 	add_entity(&obj,
// 		create_node_obj(create_cone(create_vector(1000,0,-1500), create_vector(0.5,0.5,0), (t_color){1,1,0}, 10) ,CONE));
// 	add_entity(&obj,
// 		create_node_obj(create_cone(create_vector(1000,0,-1500), create_vector(0.5,-0.5,0), (t_color){1,1,0}, 10) ,CONE));
// 	add_entity(&obj,
// 		create_node_obj(create_cone(create_vector(1000,0,-1500), create_vector(-1,0,0), (t_color){1,1,0}, 10) ,CONE));
// 	add_entity(&obj,
// 		create_node_obj(create_cone(create_vector(1000,0,-1500), create_vector(0,-1,0), (t_color){1,1,0}, 10) ,CONE));
// 	add_entity(&obj,
// 		create_node_obj(create_plane(create_vector(2000, 0, -3000),create_vector(0, 0, 1),(t_color){0.3, 0.3, 0.3}), PLANE));
// 	add_entity(&obj,
// 		create_node_obj(create_sphere(create_vector(1000, 100, -1500), (t_color){1, 0, 0}, 600), SPHERE));
// 	scene->obj = obj;
// 	scene->lights = lights;
// }

// void init_scene_4(t_scene *scene)
// {
// 	t_list_obj *obj;
// 	t_light *lights;

// 	obj = NULL;
// 	lights = NULL;
// 	add_node_light(&lights,create_light(create_vector(900, 0, 500),
// 		(t_color){0.8, 0.8, 0.8}, 20));
// 	add_entity(&obj, create_node_obj(create_cylinder(create_vector(300, 0, 300), 
// 		create_vector(1,0, -0.5),100, (t_color){0,0,1}), CYLINDER));
// 	add_entity(&obj,
// 		create_node_obj(create_cone(create_vector(300,0,300), create_vector(0,1,0), (t_color){1,1,0}, 30) ,CONE));
// 	add_entity(&obj, create_node_obj(create_cylinder(create_vector(300, 0, 300), 
// 		create_vector(0.5,0.5,0),100, (t_color){0,0,1}), CYLINDER));
// 	add_entity(&obj,
// 		create_node_obj(create_sphere(create_vector(300, 0, 300), (t_color){1, 0, 0}, 300), SPHERE));
// 	scene->obj = obj;
// 	scene->lights = lights;
// }

// void init_scene_5(t_scene *scene)
// {
// 	t_list_obj *obj;
// 	t_light *lights;

// 	obj = NULL;
// 	lights = NULL;
// 	add_node_light(&lights,create_light(create_vector(900, 900, 500),
// 		(t_color){0.8, 0.8, 0.8}, 30));
// 	add_entity(&obj,
// 		create_node_obj(create_sphere(create_vector(300, 0, 300), (t_color){1, 0, 0}, 300), SPHERE));
// 	add_entity(&obj,
// 		create_node_obj(create_sphere(create_vector(900, 0, 300), (t_color){1, 0, 0}, 300), SPHERE));
// 	add_entity(&obj, create_node_obj(create_cylinder(create_vector(300, -500, 300), 
// 		create_vector(1, 0,0),100, (t_color){0,0,1}), CYLINDER));
// 	add_entity(&obj, create_node_obj(create_cylinder(create_vector(300, -500, 300), 
// 		create_vector(0.3, 0.3,0),100, (t_color){0,0,1}), CYLINDER));
// 	scene->obj = obj;
// 	scene->lights = lights;
// }