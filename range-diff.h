#ifndef RANGE_DIFF_H
#define RANGE_DIFF_H

#include "diff.h"
#include "strvec.h"

#define RANGE_DIFF_CREATION_FACTOR_DEFAULT 60

struct range_diff_options {
	int creation_factor;
	unsigned dual_color:1;
	const struct diff_options *diffopt;
	const struct strvec *other_arg;
};

/*
 * Compare series of commits in RANGE1 and RANGE2, and emit to the
 * standard output.  NULL can be passed to DIFFOPT to use the built-in
 * default.
 */
int show_range_diff(const char *range1, const char *range2,
		    struct range_diff_options *opts);

/*
 * Determine whether the given argument is usable as a range argument of `git
 * range-diff`, e.g. A..B. Note that this only validates the format but does
 * _not_ parse it, i.e. it does _not_ look up the specified commits in the
 * local repository.
 */
int is_range_diff_range(const char *arg);

#endif
