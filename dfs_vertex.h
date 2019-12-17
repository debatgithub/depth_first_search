#ifndef __INCLUDE_DFS_VERTEX_H__
#define __INCLUDE_DFS_VERTEX_H__
#include <iostream>
typedef enum e_vertex_color { WHITE_COLOR = 0, GRAY_COLOR = 1, BLACK_COLOR = 2 } VERTEX_COLOR;
class dfs_vertex
{

public:
    dfs_vertex() { };
    dfs_vertex (std::string _name, int _index ) { name = _name; index = _index; color = WHITE_COLOR; discovery = 0; finish = 0; weight = 1; predecessor = -1; };
    dfs_vertex(const dfs_vertex& v) { name = v.name; index = v.index; color = v.color; weight = v.weight; discovery = v.discovery; finish = v.finish; predecessor = v.predecessor; };
    std::string get_name(void ) { return name; };
    int get_predecessor(void ) { return predecessor; };
    int get_index(void ) { return index; };
    int get_weight(void ) { return weight; };
    int get_discovery(void ) { return discovery; };
    int get_finish(void ) { return finish; };
    VERTEX_COLOR get_color(void ) { return color; };
    void set_name(std::string _name ) { name = _name; };
    void set_predecessor(int _predecessor ) { predecessor = _predecessor; };
    void set_index(int _index ) { index = _index; };
    void set_weight(int _weight ) { weight = _weight; };
    void set_color(VERTEX_COLOR _color ) { color = _color; };
    void set_discovery(int _discovery ) { discovery = _discovery; };
    void set_finish(int _finish) { finish = _finish; };
    void print_dfs_vertex (void ) { 
           std::cout << "name = " << name << ", color = " << color << ", discovery = " << discovery << ", finish = " << finish << ", weight = " << weight << ", predecessor = " << predecessor << std::endl;
    };
private:
    std::string name;
    int predecessor;
    VERTEX_COLOR color;
    int index;
    int discovery;
    int finish;
    int weight;

};
#endif // __INCLUDE_DFS_VERTEX_H__
