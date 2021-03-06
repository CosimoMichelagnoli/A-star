#include "MapSearchNode.h"
#include "Mappa.h"
#include "Personaggio.h"


bool MapSearchNode::IsSameState( MapSearchNode &rhs )
{
    return (x == rhs.x) && (y == rhs.y);
}

void MapSearchNode::PrintNodeInfo()
{
    Personaggio::Instance()->setPers(x*80,y*80);
    //Mappa::Instance()->setLvlmap(x,y);

    cout << "Node position:(" << x << "," << y << ")" << std::endl;
}

float MapSearchNode::GoalDistanceEstimate( MapSearchNode &nodeGoal )
{
    return std::abs(x - nodeGoal.x) + std::abs(y - nodeGoal.y);
}

bool MapSearchNode::IsGoal( MapSearchNode &nodeGoal )
{
    return (x == nodeGoal.x) && (y == nodeGoal.y);
}

bool MapSearchNode::GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node )
{
    
    int parent_x = -1;
    int parent_y = -1;
    
    if( parent_node )
    {
        parent_x = parent_node->x;
        parent_y = parent_node->y;
    }
    MapSearchNode NewNode;
    if( (Mappa::Instance()->getMap( x-1, y ) < 9)
       && !((parent_x == x-1) && (parent_y == y))
       )
    {
        NewNode = MapSearchNode(x-1, y);
        astarsearch->AddSuccessor( NewNode );
    }
    
    if( (Mappa::Instance()->getMap( x, y-1 ) < 9)
       && !((parent_x == x) && (parent_y == y-1))
       )
    {
        NewNode = MapSearchNode( x, y-1);
        astarsearch->AddSuccessor( NewNode );
    }
    
    if( (Mappa::Instance()->getMap( x+1, y ) < 9)
       && !((parent_x == x+1) && (parent_y == y))
       )
    {
    NewNode = MapSearchNode( x+1, y);
    astarsearch->AddSuccessor( NewNode );
}
    
    
    if( (Mappa::Instance()->getMap( x, y+1 ) < 9)
       && !((parent_x == x) && (parent_y == y+1))
       )
    {
        NewNode = MapSearchNode( x, y+1);
        astarsearch->AddSuccessor( NewNode );
    }
    return true;
}

float MapSearchNode::GetCost( MapSearchNode &successor )
{
    return (float) Mappa::Instance()->getMap( x, y );
}
