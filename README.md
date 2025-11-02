# Test C++ Build Actions

This is a test project that builds a small C++ program in a
Debian container on an Ubuntu GitHub runner, and directly on
a GitHub runner VM on Windows.

A GitHub run number, which is the only variable that can be used
for build numbers, is restarted from `1` when the workflow file
is renamed. In addition to this, GitHub requires a workflow file
to exist in `main` in order to run a workflow on any branch.
This requires very careful workflow maintenance to match typical
pipelines in other CI environments, such as Azure DevOps.
