#include "engine.h"

void			*ft_realloc(void *mem, int size, size_t segment)
{
	void	*remem;

	if (!mem)
		return (ft_memalloc(size * segment));
	remem = malloc(size * segment);
	if (!remem)
	{
		free(mem);
		return (0);
	}
	remem = ft_memcpy(remem, mem, --size * segment);
	free(mem);
	return (remem);
}
