

%% Create a distribution of minimal discharge rates of a pool
pool_parameter.m
MDR_distribution.m

%% Specify MN parameters
electrical_parameters.m
conductance_parameters.m

%% Test passive electrical properties
test_input_resistance.m

%% Find recruitment threshold and minimal discharge rate of individual MNs
test_recruitment_threshold.m

%% Fit model parameters to adjust minimal discharge rate to the deisred value
MDR_fit.m

%% Generate a strcture variable, mn_parameter, to run a population MN model
mn_parameter_pool.m

%% Test the MN population model
test_MN_model_population.m % the code that runs the model
MN_model_population.m % function for the model
