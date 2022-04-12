[![<kharchenkolab>](https://circleci.com/gh/kharchenkolab/cacoa.svg?style=svg)](https://app.circleci.com/pipelines/github/kharchenkolab/cacoa)


# cacoa

Case-Control Analysis of scRNA-seq experiments

As the method is not published yet, there is no text description available. To get some idea of how it works you may want to check [the slides](https://slides.com/vpetukhov/cacoa-scs-sept-2021) from the method presentation.

## Installation

To install the latest version, use:

```r
install.packages('devtools')
devtools::install_github('kharchenkolab/cacoa')
```


Prior to installing the package, dependencies have to be installed:

```r
BiocManager::install(c("clusterProfiler", "DESeq2", "DOSE", "EnhancedVolcano", "enrichplot", "fabia", "GOfuncR", "Rgraphviz"))
```

Also make sure to install [sccore](https://github.com/kharchenkolab/sccore) and [conos](https://github.com/kharchenkolab/conos).


## Initialization

Cacoa currently supports inputs in several formats (see below). Most of them require the following metadata:

- `sample.groups`: vector with condition labels per sample named with sample ids
- `cell.groups`: cell type annotation vector named by cell ids
- `sample.per.cell`: vector with sample labels per cell named with cell ids
- `ref.level`: id of the condition, corresponding to the reference (i.e. control)
- `target.level`: id of the condition, corresponding to the target (i.e. case)

### Raw or normalized joint count matrix `cm`

```r
cao <- Cacoa$new(cm, sample.groups=sample.groups, cell.groups=cell.groups, sample.per.cell=sample.per.cell, 
                 ref.level=ref.level, target.level=target.level, embedding=embedding)
```

Parameter `embedding` contains a matrix or data.frame with a cell embedding. Rownames should match to the cell ids. It is used for visualization and some cluster-free analysis.

### Seurat object `so`

```r
cao <- Cacoa$new(so, sample.groups=sample.groups, cell.groups=cell.groups, sample.per.cell=sample.per.cell, 
                 ref.level=ref.level, target.level=target.level, graph.name=graph.name)
```

Parameter `graph.name` is required for cluster-free analysis, and must contain a name of joint graph in Seurat object. For that, the Seurat object must have a joint graph estimated (see [FindNeighbors](https://satijalab.org/seurat/reference/findneighbors)). For visualization purposes, Seurat also must have cell embedding estimated or the embedding data frame must be provided in the `embedding` parameter.

### Conos object `co`

```r
cao <- Cacoa$new(co, sample.groups=sample.groups, cell.groups=cell.groups, 
                 ref.level=ref.level, target.level=target.level)
```

For visualization purpuses, Conos must have cell embedding estimated or the embedding data frame must be provided in the `embedding` parameter. And for cluster-free analysis it should have a joint graph (see the method `Conos$buildGraph()` from [conos](https://CRAN.R-project.org/package=conos) method).

## Usage

Cacoa can estimate and visualize various statistics. Most of them have paired functions `cao$estimateX(...)` and `cao$plotX(...)` (for example, `cao$estimateCellLoadings()` and `cao$plotCellLoadings()`). Results of all estimation are stored in `cao$test.results`, and their exact name can be controlled by `name` parameter passed to `cao$estimateX()`. For example, calling `cao$estimateExpressionShiftMagnitudes(name='es')` would save the results in `cao$test.results$es`.

Please, see the documentation for exact functions inside the package. For a demonstration see [the vignette](http://pklab.med.harvard.edu/viktor/cacoa/ep.html). Additionally, the [cacoaAnalysis](https://github.com/kharchenkolab/cacoaAnalysis/) repository contains analysis conducted inside the paper, though the Cacoa version there may be out of date.


