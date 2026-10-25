#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_config	cfg;

	if (argc < 2)
		return (0);
	cfg.mode = MODE_NORMAL;
	cfg.bench = 0;
	cfg.stack_a = NULL;
	cfg.stack_b = NULL;
	parse_args(argc, argv, &cfg);
	/*
	 * Run sorting strategy according to cfg.mode:
	 *   - MODE_SIMPLE  -> e.g., insertion / selection sort logic
	 *   - MODE_NORMAL  -> standard radix / chunk sort
	 *   - MODE_COMPLEX -> Turk algorithm / cost calculation sort
	 * If cfg.bench is active, output instruction counts to stderr/stdout.
	 */
	free_stack(&cfg.stack_a);
	free_stack(&cfg.stack_b);
	return (0);
}
