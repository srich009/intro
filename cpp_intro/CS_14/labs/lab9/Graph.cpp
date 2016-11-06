#include "Graph.h"


Graph::Graph(){
    
}

Graph::~Graph() {
    
}

Graph::Graph(ifstream& ifs) {
    int N = 0;
    int M = 0;
    map<string, int> m;
    
    ifs >> N;
    ifs >> M;
    
    for (int i = 0; i < N; i++) {
        string str;
        Vertex v;
        ifs >> str;
        v.label = str;
        vertices.push_back(v);
        m[str] = i;
    }
    
    while (ifs) { // !ifs.eof()
        string u;
        string v;
        int c;
        ifs >> u;
        ifs >> v;
        ifs >> c;
        int index = m[u];
        int nindex = m[v];
        pair<int, int> p (nindex,  c);
        
        vertices.at(index).neighbors.push_back(p);
    }

}

void Graph::output_graph(const string & filename) 
{
        ofstream outFS(filename.c_str());
        if(!outFS.is_open()){
            cout<<"Error"<<endl;
            return;
        }
        outFS<<"digraph G {"<<endl;
        visualize(outFS,vertices);
        outFS<<"}";
        outFS.close();
        string jpgFilename = filename.substr(0,filename.size()-4)+".jpg";
        string command = "dot -Tjpg " + filename + " -o " + jpgFilename;
        system(command.c_str());
}

void Graph::visualize(ofstream& out, vector<Vertex> &v) {
 if (v.empty()) return;
    
    for (unsigned int i = 0; i < v.size(); i++ ) {
        
        for (list<pair<int, int> >::iterator it = temp.neighbors.begin(); it != temp.neighbors.end(); it++) {
         
        }
        
    }
    // out << curr->key << " [color = lightblue, style = filled, label =\""
    //     << curr->data << "\"]" << endl;
    
    // if (curr->left != 0)
    //     out << curr -> key << " -> " << curr->left->key << endl;
    // if (curr->right != 0)
    //     out << curr -> key << " -> " << curr->right->key << endl;
    
    // visualize(out, curr->left);
    // visualize(out, curr->right);
}




void Graph::bfs() 
{	
	for(unsigned int i = 0; i < vertices.size(); i++) 
	{
	    vertices.at(i).distance = INT_MAX;
	    vertices.at(i).color = "WHITE";
	    vertices.at(i).prev = 0;
	}
	
	vertices.at(0).color = "GRAY";
	vertices.at(0).distance = 0;
	vertices.at(0).prev = 0;
	queue<Vertex> Q;
	Q.push(vertices.at(0));
    while(!Q.empty()) 
    {
        Vertex temp = Q.front();
        Q.pop();
        for (list<pair<int, int> >::iterator it = temp.neighbors.begin(); it != temp.neighbors.end(); it++) 
        {
         
            if(vertices.at(it -> first).color == "WHITE" )
            {
                vertices.at(it -> first).color == "GRAY";
                vertices.at(it -> first).distance = temp.distance + 1; 
                vertices.at(it -> first).prev = &temp;
                Q.push(vertices.at(it -> first));
                
            }
        } 
    }
}

