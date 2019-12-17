#include <iostream>
#include "dfs_vertex.h"
int main (void );
#define VERTEX_NUM 6
dfs_vertex * dfs_vertices[VERTEX_NUM];
int adj_matrix_dfs_vertices[VERTEX_NUM][VERTEX_NUM];
void depth_first_search (dfs_vertex ** dfs_vertices, int p_adj_matrix_dfs_verices[][VERTEX_NUM], int vertex_count );
void depth_first_search_visit (dfs_vertex ** dfs_vertices, int p_adj_matrix_dfs_verices[][VERTEX_NUM], dfs_vertex * u, int vertex_count );
void print_depth_first_search_result (dfs_vertex ** dfs_vertices, int vertex_count );

int dfs_time = 0;

int main (void ) 
{
int i, j;

    for (i = 0; i < VERTEX_NUM; i++) {
        for (j = 0; j < VERTEX_NUM; j++) {
            adj_matrix_dfs_vertices[i][j] = 0;
        }
    }
    dfs_vertices[0] = new dfs_vertex("1", 0);
    dfs_vertices[1] = new dfs_vertex("2", 1);
    dfs_vertices[2] = new dfs_vertex("3", 2);
    dfs_vertices[3] = new dfs_vertex("4", 3);
    dfs_vertices[4] = new dfs_vertex("5", 4);
    dfs_vertices[5] = new dfs_vertex("6", 5);
    adj_matrix_dfs_vertices[0][1] = 1;
    adj_matrix_dfs_vertices[0][3] = 1;
    adj_matrix_dfs_vertices[1][4] = 1;
    adj_matrix_dfs_vertices[2][4] = 1;
    adj_matrix_dfs_vertices[2][5] = 1;
    adj_matrix_dfs_vertices[3][1] = 1;
    adj_matrix_dfs_vertices[4][3] = 1;
    adj_matrix_dfs_vertices[5][5] = 1;
    
    depth_first_search(dfs_vertices, adj_matrix_dfs_vertices, VERTEX_NUM );
    print_depth_first_search_result(dfs_vertices, VERTEX_NUM );
    return 0;
};


void depth_first_search (dfs_vertex ** p_dfs_vertices, int p_adj_matrix_dfs_vertices[][VERTEX_NUM], int vertex_count )
{
   for (int i = 0; i < vertex_count; i++) {
       p_dfs_vertices[i]->set_color(WHITE_COLOR);
       p_dfs_vertices[i]->set_predecessor(-1);
   }
   dfs_time = 0;
   for (int i = 0; i < vertex_count; i++) {
       dfs_vertex * u = p_dfs_vertices[i];
       if (u->get_color() == WHITE_COLOR)
           depth_first_search_visit(p_dfs_vertices, p_adj_matrix_dfs_vertices, u, vertex_count );
   }
}

void depth_first_search_visit (dfs_vertex ** p_dfs_vertices, int p_adj_matrix_dfs_vertices[][VERTEX_NUM], dfs_vertex * u, int vertex_count )
{
   dfs_time++;
   u->set_discovery(dfs_time);
   u->set_color(GRAY_COLOR);
   int u_index = u->get_index();
   for (int j = 0; j < vertex_count; j++) {
       if (p_adj_matrix_dfs_vertices[u_index][j] == 1) {
           dfs_vertex * v = p_dfs_vertices[j];
           if (v->get_color() == WHITE_COLOR) {
                v->set_predecessor(u_index);
                depth_first_search_visit(p_dfs_vertices, p_adj_matrix_dfs_vertices, v, vertex_count );
           }
       }
   }
   u->set_color(BLACK_COLOR);
   dfs_time++;
   u->set_finish(dfs_time);
}
      
 
void print_depth_first_search_result (dfs_vertex ** p_dfs_vertices, int vertex_count )
{
   for (int i = 0; i < vertex_count; i++) 
       p_dfs_vertices[i]->print_dfs_vertex();
    
}

        
