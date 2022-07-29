# Test C++ Build Actions

This is a test project that builds a C++ one-liner on Debian and
on Windows via GitHub actions for projects that maintain past
releases for bug fixes and minor improvements, which requires
more than one active branch.

A GitHub run number, which is the only variable that can be used
for build numbers, is restarted from `1` when the workflow file
is renamed. In addition to this, GitHub requires that a workflow
file existed in `main` in order to run a workflow in a branch.
All this requires very careful workflow maintenance to match
typical pipelines in other CI environments, such as Azure DevOps.

Current layout of this test repository works for dot zero releases
made from `main`, which is typical for smaller projects, or made
from a dedicated release branch that is merged back into `main`
*once* after the dot-zero release and then continues on its own
for bug fixes and minor improvements.

The `2.6.0` tag and `2.6.x` branch show the former and `2.8.0`
tag and `2.8.x` branch show the latter.

In this layout, past runs are shown in GitHub actions, but it
is not possible to run a workflow of the past version in GitHub.
That is, once `2.8.0` is released and the version is changed to
the next planned one, such as `3.0.0`, there is no workflow
available to build `2.8.0` in GitHub actions. This by design,
so only active releases are being visible in GitHub Actions
and to enforce a single set of release artifacts for a given
version.
