#ifndef NODE_LOCATION_HPP_DEFINED
#define NODE_LOCATION_HPP_DEFINED 

namespace ast
{
	class NodeLocation
	{
	public:
		// constructors
		NodeLocation();

		// params : first_line, last_line, first_column, last_column
		// throws a domain error of the first/last_line are invalid
		NodeLocation(int, int, int, int);

		// accessors
		int first_line() const;
		int last_line() const;
		int first_column() const;
		int last_column() const;

		//setters
		// line setters throw a domain  error if the first/last_line are invalid
		void set_first_line(int);
		void set_last_line(int);
		void set_lines(int, int);
		void set_first_column(int);
		void set_last_column(int);

	private:
		int first_line_; // line at which starts the element
		int last_line_; // line at which ends the element
		int first_column_; // column at which starts the element
		int last_column_; // column at which ends the element
	};
}

#endif // NODE_LOCATION_HPP_DEFINED