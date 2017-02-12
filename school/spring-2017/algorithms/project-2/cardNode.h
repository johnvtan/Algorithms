class cardNode
{
	public:
		// data members
		card c;
		cardNode *next;
		
		// constructors
		cardNode() {}
        
        // changed, but we never use this anyway
		cardNode(const cardNode& head) {
			c = head.c;
			next = head.next;
		}
	
};

