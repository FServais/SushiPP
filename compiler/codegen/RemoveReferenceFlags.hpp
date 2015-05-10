#ifndef REMOVE_REFERENCE_FLAGS_HPP_DEFINED
#define REMOVE_REFERENCE_FLAGS_HPP_DEFINED

#include <vector>
#include <string>

namespace codegen
{
    /**
      * @class RemoveReferenceFlags
      * @brief The class keeps track on which array/list should be freed at the end of a certain scope.
      */
    class RemoveReferenceFlags
    {
    public:
        RemoveReferenceFlags() { }

        /**
         * @brief Adds a flag, meaning that the array/list has to be freed.
         * @param const std::string var Name of the variable containing the ID of the array/list.
         * @param const int scope_id ID of the scope where is defined the array/list.
         */
        void add_flag(const std::string, const int);

        /**
         * @brief Check if there is a flag for a variable at a certain scope.
         * @param const std::string var Name of the variable containing the ID of the array/list.
         * @param const int scope_id ID of the scope where is defined the array/list.
         * @retval bool True if a flag is set, false otherwise.
         */
        bool is_present(const std::string, const int) const;

        /**
         * @brief Get the list of the variables to free in the given scope.
         * @param const int scope_id ID of the scope where is defined the array/list.
         * @retval std::vector<std::string> Vector containing the name of the variables in the scope.
         */
        std::vector<std::string> pop_vars_at_scope(const int);

        void print() const;

    private:
        std::vector<std::pair<std::string, int>> entries;

    };

}

#endif
