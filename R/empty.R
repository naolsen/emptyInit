
#' emptyInit
#'
#' @description emptyInit is a small package for fast initialization of numeric-type vectors. Intended only for experienced R users.
#'
#' Why use it?: By default, R assigns NA or 0 to all elements
#' whenever a vector, matrix or array is initialized using \code{numeric}, \code{matrix} or \code{array}.
#'
#' This is a waste if you're going to overwrite all the elements anyway, e.g. by looping over columns.
#' Therefore, emptyInit only allocates memory, but does not assign nor check values
#' (and thus, whatever was in the memory beforehand will be the values of your vector)
#'
#' What to be aware of?: As the memory can contain whatever values, the values are not likely to be of any sense and should be overwritten.
#'
#' Is it safe?: It is complety safe, but there is no reproducibility.
#'
#' Is it fast?: The computational speed is O(1) + time(memory allocation), the latter which is handled internally by R.
#' For small n (~ < 1000), \code{numeric} is faster, but for large n emptyInit is many times faster.
#'
#' What about vectorization? Well, if you can vectorize your code, this would likely be a better option.
#' But vectorization can require much work and your code might depend on some functions that are not vectorizable.
#'
#' @docType package
#' @author Niels Olsen
#'
#' @name emptyInit-package
NULL


#' emptyArray
#'
#' Creates an empty array
#'
#' @param dim Dimensions
#' @param dimnames Optional names for the dimensions.
#'
#' @details emptyArray makes a call to emptyNumeric, but is otherwise similar to \link{array} in functionality.
#'
#' @return An array with dimensions specified by \code{dim}.
#'
#' @export
#'
#' @seealso \link{emptyNumeric}, \link{emptyMatrix}
#'
emptyArray <- function(dim = length(data), dimnames = NULL) {
  dim <- as.integer(dim)
  if (!length(dim))
    stop("'dims' cannot be of length 0")
  vl <- prod(dim)
  if (vl > .Machine$integer.max)
    stop("'dim' specifies too large an array")
  a <- emptyNumeric(vl)
  dim(a) <- dim
  if (is.list(dimnames) && length(dimnames))
    dimnames(a) <- dimnames
  a
}


#emptyMatrix <- function(nrow, ncol) {
#  storage.mode(nrow) <- "integer"
#  .Call('_emptyInit_emptyMatrix', PACKAGE = 'emptyInit', nrow, ncol)
#}



